"""Model for aircraft flights."""


class Flight:
    """A flight with a particular passenger aircraft"""

    # def __init__(self, number):
    # Passing an aircraft instance to the Flight Class.
    def __init__(self, number, aircraft):
        #Using Class Invariants - That make arguments follow a specific rule-set
        if not number[:2].isalpha():
            raise ValueError(f"No airline code in '{number}'")

        if not number[:2].isupper():
            raise ValueError(f"Invalid airline code '{number}'")

        if not (number[2:].isdigit() and int(number[2:]) <= 9999):
            raise ValueError(f"Invalid route number '{number}'")

        self._number = number
        self._aircraft = aircraft

        rows, seats = self._aircraft.seating_plan()
        self._seating = [None] + \
            [{letter: None for letter in seats} for _ in rows]

    def aircraft_model(self):
        return self._aircraft.model()
        #number() is already a function
        #By convention, implementation details start with _

    def number(self):
        return self._number

    def airline(self):
        return self._number[:2]

    # TypeError if self is not given as an argument
    def allocate_seat(self, seat, passenger):

        row, letter = self._parse_seat(seat)

        if self._seating[row][letter] is not None:
            raise ValueError(f"Seat {seat} already occupied")

        self._seating[row][letter] = passenger

    # Refactored the code by making this code into its own function.
    def _parse_seat(self, seat):
        # Also there's an underscore in front of the name
        rows, seat_letters = self._aircraft.seating_plan()
        letter = seat[-1]
        if letter not in seat_letters:
            raise ValueError(f"Invalid seat letter {letter}")

        row_text = seat[:-1]
        try:
            row = int(row_text)
        except ValueError:
            raise ValueError(f"Invalid seat row {row_text}")

        if row not in rows:
            raise ValueError(f"Invalid row number {row}")
        return row, letter

    def relocate_passenger(self, from_seat, to_seat):
        from_row, from_letter = self._parse_seat(from_seat)
        if self._seating[from_row][from_letter] is None:
            raise ValueError(f"No passenger to relocate in seat {from_seat}")

        to_row, to_letter = self._parse_seat(to_seat)
        if self._seating[to_row][to_letter] is not None:
            raise ValueError(f"Seat {to_seat} is already occupied")

        self._seating[to_row][to_letter] = self._seating[from_row][from_letter]
        self._seating[from_row][from_letter] = None

    def num_available_seats(self):
        return sum(sum(1 for s in row.values() if s is None)
                for row in self._seating
                if row is not None)

    def boarding_card(self,card_printer):
        for passenger,seat in sorted(self._passenger_seats()):
            card_printer(passenger,seat,self.number(),self.aircraft_model())

    def _passenger_seats(self): #Generator function
        row_numbers,seat_letter = self._aircraft.seating_plan()
        for row in row_numbers:
            for letter in seat_letter:
                passenger = self._seating[row][letter]
                if passenger is not None:
                    yield (passenger, f"{row}{letter}")


class Aircraft:

    def __init__(self, registration):
        self._registration = registration

    def registration(self):
        return self._registration

    def num_seats(self):
        rows, row_seats = self.seating_plan() # This is a base class and this can be done because Python is late binding
        return len(rows) * len(row_seats)

#     def __init__(self, registration, model, num_rows, num_seats_per_row):
#         self._registration = registration
#         self._model = model
#         self._num_rows = num_rows
#         self._num_seats_per_row = num_seats_per_row

#     def registration(self):
#         return self._registration

#     def model(self):
#         return self._model

#     def seating_plan(self):
#         return (range(1, self._num_rows+1),
#                 "ABCDEFGHJK"[:self._num_seats_per_row])  # Actually limits the number of seats per row!


class AirbusA319(Aircraft):

    # def __init__(self, registration):
    #     self._registration = registration

    # def registration(self):
    #     return self._registration

    def model(self):
        return "Airbus A319"

    def seating_plan(self):
        return range(1, 23), "ABCDEF"  # Actually limits the number of seats per row!


class Boeing777(Aircraft):

    # def __init__(self, registration):
    #     self._registration = registration

    # def registration(self):
    #     return self._registration
    
    def model(self):
        return "Boeing 777"

    def seating_plan(self):
        return range(1, 56), "ABCDEGHJK"  # Actually limits the number of seats per row!



def console_card_printer(passenger,seat,flight_number,aircraft):
    output = f"| Name: {passenger}"        \
             f"  Flight: {flight_number}"  \
             f"  Seat: {seat}"             \
             f"  Aircraft: {aircraft}"     \
             " |"
    banner = "+" + "-" * (len(output) - 2) + "+"
    border = "|" + " " * (len(output) - 2) + "|"
    lines = [banner,border,output,border,banner]
    card = "\n".join(lines)
    print(card)
    print()


def make_flights():
    # f = Flight("BA758", Aircraft("G-EUPT","Airbus A319", num_rows=22, num_seats_per_row=6))
    f = Flight("BA758",AirbusA319("G-EUPT"))
    
    f.allocate_seat("12A","Guido")
    f.allocate_seat("15F","Bjarne")
    f.allocate_seat("15E","Anders")
    f.allocate_seat("1C","John")
    f.allocate_seat("1D","Rich")
    f.allocate_seat("12B","Guido 2.0")
    
    g = Flight("AF72",Boeing777("F-GSPS"))
    
    g.allocate_seat("12A","Guido")
    g.allocate_seat("15G","Bjarne")
    g.allocate_seat("15E","Anders")
    g.allocate_seat("1C","John")
    g.allocate_seat("1D","Rich")
    g.allocate_seat("12B","Guido 2.0")

    return f,g