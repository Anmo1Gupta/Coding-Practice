class Textbook{
    constructor(textbookName, textbookISBN, textbookAuthor){
        this.tName = textbookName;
        this.tISBN = textbookISBN;
        this.tAuthor = textbookAuthor;
    }
    get name() {
        return this.tName;
    }
    set name(name) {
        this.tName = name;
    }
    get ISBN() {
        return this.tISBN;
    }
    set ISBN(ISBN) {
        this.tISBN = ISBN;
    }
    get author() {
        return this.tAuthor;
    }
    set author(author) {
        this.tAuthor = author;
    }
    toString() {
        return `'Text Book:' + ${this.textbook.tName} + ', ISBN: ' + ${this.textbook.tISBN}`;
    }
}


class Instructor {
    constructor(name, ID, email) {
        this.iName = name;
        this.iID = ID;
        this.iEmail = email;
    }
    get name() {
        return this.iNname;
    }
    set name(instructorName) {
        this.iNname = instructorName;
    }

    set ID(instructorID) {
        this.iID = instructorID;
    }

    get ID() {
        return this.iID;
    }

    get email() {
        return this.iEmail;
    }
    set email(instructorEmail) {
        this.iEemail = instructorEmail;
    }

    toString() {
        return `Instructor: ${this.iName} ,  ${this.iID} , ${this.iEmail}`;
    }


}

class Course {
    constructor(name, creditHours, CRN, instructor, textbook) {
        this.cName = name;
        this.cCreditHours = creditHours;
        this.cCRN = CRN;
        this.cInstructor = instructor;
        this.cTextbook = textbook;
    }

    get name() {
        return this.cName;
    }
    set name(courseName) {
        this.cName = courseName;
    }

    get creditHours() {
        return this.cCreditHours;
    }
    set creditHours(courseCreditHours) {
        this.cCreditHours = courseCreditHours;
    }

    get CRN() {
        return this.cCRN;
    }
    set CRN(courseCRN) {
        this.cCRN = courseCRN;
    }

    get instructor() {
        return this.cInstructor;
    }
    set instructor(courseInstructor) {
        this.cInstructor = courseInstructor;
    }

    get textbook() {
        return this.cTextbook;
    }
    set textbook(courseTextbook) {
        this.cTextbook = courseTextbook;
    }

    toString() {
        return `
        Course Name: ${this.cName} , CRN: ${this.cCRN} 
        Instructor: ${this.instructor.iName} , ${this.instructor.iID} , ${this.instructor.iEmail}
        Text Book: ${this.textbook.tName} , ISBN:  ${this.textbook.tISBN}
        `;
    }
}

const textbook1 = new Textbook("Learning Java", "123-5555-6635", "John Anderson");
const textbook2 = new Textbook("Learning JavaScript", "123-5245-6625", "Amy Henderson");

const instructor1 = new Instructor("John Adams", "ID#1234","john.adams@email.com");

const course1 = new Course("Advanced Java 3 Credits","3","34345",instructor1,textbook1);
console.log(course1);
console.log(course1.toString());


