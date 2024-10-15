# include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>


using namespace std;

const char* HOST="localhost";
const char* USER="root";
const char* PW="root";
const char* DB="db";


int main(){
	
	MYSQL* conn;
	
	conn=mysql_init(NULL);
	
	if(!mysql_real_connect(conn,HOST,USER,PW,DB,3306,NULL,0)){
		cout<<"\t \t Error:"<<mysql_error(conn)<<endl;
	}
	
	else{
		cout<<"\t \t Logged In!!"<<endl;
	}
	Sleep(3000);
	
	bool exit =false;
	
	while(!exit){
		
		system("cls");
		
		
		cout<<"\t \t WELCOME TO SQL"<<endl;
		cout<<"\t \t********************"<<endl;
		cout<<"\t \t 1. INSERT DATA."<<endl;
		cout<<"\t \t 2. DELETE DATA."<<endl;
		cout<<"\t \t 3. UPDATE DATA."<<endl;
		cout<<"\t \t 4. READ/VIEW DATA."<<endl;
		cout<<"\t \t 0. EXIT."<<endl;
		
		cout<<endl<<endl;
		cout<<"Enter a choice: ";
		int val;
		cin>>val;
		
		if(val==1){
			system("cls");
			
			
			string name, rollno,phone;
			
			cout<<endl<<endl;
			
			cout<<"\t \t Enter Name: ";
			cin>>name;
			cout<<endl;
			cout<<"\t \t Enter Roll No. : ";
			cin>>rollno;
			cout<<endl;
			cout<<"\t \t Enter Phone Number: ";
			cin>>phone;
			
			string ins="INSERT INTO students(Roll_No,Name,Phone) VALUES('"+rollno+"','"+name+"','"+phone+"')";
			
			if(mysql_query(conn,ins.c_str())){
				
				cout<<endl<<endl;
				cout<<"\t \t Error: "<<mysql_error(conn)<<endl;
				
				
			}
			
			else {
				
				cout<<endl<<endl;
				cout<<"\t \t DATA INSERTED SUCCESSFULLY!";
				
			}
		Sleep(3000);
		}
		
		
		
		else if(val==2){
			system("cls");
			cout<<endl<<endl;
			string rollno;
			
			
			cout<<"\t \t Enter The roll no. you want to Delete: ";
			cin>>rollno;
			
			string del="DELETE FROM students WHERE Roll_No='"+rollno+"'";
			
			
			if(mysql_query(conn,del.c_str())){
					cout<<endl<<endl;
				cout<<"\t \t Error: "<<mysql_error(conn)<<endl;
				
				
			}
			
			else {
				
				cout<<endl<<endl;
				cout<<"\t \t DATA DELETED SUCCESSFULLY!";
				
			}
		Sleep(3000);
				
						
		}
		
		
		else if(val==3){
			system("cls");
			cout<<endl<<endl;
			
			cout<<"\t \t Enter Roll no:  ";
			string rollno,phno;
			cin>>rollno;
			
			cout<<"\t \t Enter New Phone Number: ";
			cin>>phno;
			
			string upd="UPDATE students SET Phone = '"+phno+"' WHERE Roll_No = '"+rollno+"'";
			
			if(mysql_query(conn,upd.c_str())){
				
					cout<<endl<<endl;
				cout<<"\t \t Error: "<<mysql_error(conn)<<endl;	
				
			}
			
			
			else {
				
				cout<<endl<<endl;
				cout<<"\t \t UPDATED SUCCESSFULLY!";
				
			}
		 Sleep(3000);
				
			
	    	}
		
		
	      	
		else if(val==4){
			system("cls");
		 	cout<<endl<<endl;
			
		   string get="SELECT * FROM students";
			
			   if(mysql_query(conn,get.c_str())){
				
					cout<<endl<<endl;
				cout<<"\t \t Error: "<<mysql_error(conn)<<endl;	
				
			}
			
			else{
				MYSQL_RES* result=mysql_store_result(conn);
				if(result){
					int num=mysql_num_fields(result);
				MYSQL_ROW row;
				cout<<endl<<endl;
				cout<<"\t\t Roll NO\t\t Name\t\t Phone"<<endl;
				cout<<"\t\t -------\t\t ----\t\t -----"<<endl;
				
				while(row=mysql_fetch_row(result))
					
				for(int i=0;i<num;i++){
						
					cout<<"\t\t "<<row[i];
				}
			
					cout<<endl;
				}
			    mysql_free_result(result);
		        }  
		       }
			Sleep(10000);	
			}		

	  
    	mysql_close(conn);

        
	
    	return 0;
	
}

