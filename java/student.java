import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
// import java.util.*; 

class Student {

	public String name;
	private int physics;
	private int chemistry;
	private  int maths;
	private int average;

	public Student() {

		this.name = "John";
		this.physics = 100;
		this.chemistry = 95;
		this.maths = 95;
		this.average = 95;
	}

	public Student(String name, int physics, int chemistry, int maths) {

		this.name = name;
		this.physics = physics;
		this.chemistry = chemistry;
		this.maths = maths;
		this.average = (this.physics + this.chemistry + this.maths)/3; 
		System.out.println("avg =" +this.average);

	}

	private static Student [] readData(String filename) throws IOException {

        FileReader fr = new FileReader(filename);
        BufferedReader br = new BufferedReader(fr);

        String line[] = new String[20];

        Student s [] = new Student[20];

        if (br.ready()) {

            for (int i = 0; i < 20; i++) {

                line[i] = br.readLine();

                System.out.println(line[i]);

                s[i] = new Student(); 
                
                String str = line [i];

                String[] parts = str.split(" ");
                           
                s[i].setName(parts[0]);
                s[i].setPhysics(Integer.parseInt(parts[1]));
                s[i].setChemistry(Integer.parseInt(parts[2]));
                s[i].setMaths(Integer.parseInt(parts[3]));              

                s[i] = new Student(s[i].getName(),s[i].getPhysics(),s[i].getChemistry(),s[i].getMaths());        
            }
        }
        br.close();

            return s;  
    }

    public static void printStudents(Student[] students){
        for (Student s: students) {
            System.out.println(s.getName() + "--" + s.getAverage() + " "+ s.getPhysics() + " " + s.getChemistry()+ " " + s.getMaths());
        }
	}
	
	public Student[] sortStudentsPhysics(Student[] students, int start, int n){		
		Student temp = new Student();
		for (int k = start; k <= n+2; k++)
            for (int l = start; l <= n-k+2; l++)
                if (students[l].physics < students[l+1].physics)
                {
                    temp = students[l];
                    students[l] = students[l+1];
                    students[l+1] = temp;
                }
		return students;
	}
	public Student[] sortStudentsChemistry(Student[] students, int start, int n){		
		Student temp = new Student();
		for (int k = start; k <= n+2; k++)
            for (int l = start; l <= n-k+2; l++)
                if (students[l].chemistry < students[l+1].chemistry)
                {
                    temp = students[l];
                    students[l] = students[l+1];
                    students[l+1] = temp;
                }
		return students;
	}
	public Student[] sortStudentsMaths(Student[] students, int start, int n){		
		Student temp = new Student();
		for (int k = start; k <= n+2; k++)
            for (int l = start; l <= n-k+2; l++)
                if (students[l].maths < students[l+1].maths)
                {
                    temp = students[l];
                    students[l] = students[l+1];
                    students[l+1] = temp;
                }
		return students;
	}

	
	public Student[] sortStudents(Student[] students)
	{
		int i=0,j=0;
		int n = students.length;
		System.out.println("Size-" + n + "   " + students[0] );
		Student temp = new Student();
		//sorting by average initially
		for (j = 1 ; j < n ; j++ ) {

			int key = students[j].average;
			i = j-1;

			while((i >= 0) && (students[i].average < key)){
				temp = students[i+1];
				students[i+1] = students[i];
				students[i] = temp;
				i--;
			}
			students[i+1].average = key;
		}
		//sorting by physics marks when average marks are equal
		int count=0,start=0;
		for(int a = 1; a<n; a++){
			if(students[a-1].average == students[a].average){
				start = a;
				count=0;
				do{
					count++;
					a++;
				}while(students[a-1].average == students[a].average);
				System.out.println("count-"+count);
				sortStudentsPhysics(students,start,count);
			}
			else{
				continue;
			}
		}
		//sorting by chemistry marks when physics marks are equal
		for(int a = 1; a<n; a++){
			if(students[a-1].physics == students[a].physics){
				start = a;
				count=0;
				do{
					count++;
					a++;
				}while(students[a-1].physics == students[a].physics);
				System.out.println("count-"+count);
				sortStudentsChemistry(students,start,count);
			}
			else{
				continue;
			}
		}
		//sorting by maths marks when physics marks are equal
		for(int a = 1; a<n; a++){
			if(students[a-1].chemistry == students[a].chemistry){
				start = a;
				count=0;
				do{
					count++;
					a++;
				}while(students[a-1].chemistry == students[a].chemistry);
				System.out.println("count-"+count);
				sortStudentsMaths(students,start,count);
			}
			else{
				continue;
			}
		}
		return students;
	}

	public static void main(String[] args) throws IOException {

		Student stud [] = new Student[20];
		Student sorted_students [] = new Student[20];
        Student s_object = new Student();

        stud = readData("students.txt");
        
        sorted_students = s_object.sortStudents(stud);
        printStudents(sorted_students);

    }


	/* setting mutator */
	public void setName(String name) {
		this.name = name;
	}

	public void setPhysics(int physics) {
		this.physics = physics;
	}

	public void setChemistry(int chemistry) {
		this.chemistry = chemistry;
	}

	public void setMaths(int maths) {
		this.maths = maths;
	}

	// public void setAverage(int average) {
	// 	this.average = average;
	// }

	/* setting accessor */
	public String getName() {
		return this.name;
	}

	public int getPhysics() {
		return this.physics;
	}

	public int getChemistry() {
		return this.chemistry;
	}

	public int getMaths() {
		return this.maths;
	}

	public int getAverage() {
		return this.average;
	}

}