#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<time.h>
#include<cstdlib>
#include<stdio.h>
using namespace std;

int figureout();

fstream f1,f2,f3,f4;

int n,i,count1=0,code1[50];
int card;
int count2=0;
char user[20];
char pass[20],passw[20];

void bill();
class personal
{
  public:
     char name[25];
    long int phone_number;

    void getdat()
    {
    cout<<"\n\nEnter your name : ";
    cin>>name;
    cout<<"\nEnter your phone number : ";
    cin>>phone_number;
    }
    int ret_ph()
    {
        return phone_number;
    }
    void get_phone(long int p)
    {
        phone_number=p;
    }
    void dis()
    {
        cout<<"\n\n\t  Name - "<<name;
        cout<<"\n\n\t  Phone Number - "<<phone_number;
    }


};

class student
{
   int amount;
    int card_no;
public:
    personal p1;
    char email_id[20],password[20];
     void getdata();
    void modify();
    void display();
    void reset()
    {
        strcpy(email_id,"\0");
        strcpy(password,"\0");
        p1.phone_number=amount=card_no=0;
        strcpy(p1.name,"\0");
    }
    student()
    {
        strcpy(password,"007");
        card_no=100;
    }
    int ret_card()
    {
        return card_no;
    }
    int ret_amt()
    {
        return amount;
    }
    void get_card(int q)
    {
        card_no=q;
    }

    void get_amt(int u)
    {
        amount=u;
    }
}s;


void student :: getdata()
{
    cout<<"\n\nEnter details in your account : ";
    p1.getdat();
    cout<<"\n\nEnter your email id : ";
    cin>>email_id;
    cout<<"\n\nEnter password for the food card (4-digit pin number) : ";
    cin>>password;
    cout<<"\n\nEnter initial amount to be deposited on your card : Rs. ";
    cin>>amount;
}


void student :: display()
{
    cout<<"\n\n\t         CARD DETAILS   ";
    p1.dis();
    cout<<"\n\n\t  Card number - "<<card_no;
    cout<<"\n\n\t  Amount - Rs."<<amount;
    cout<<"\n\n\t  Email Id - "<<email_id<<endl;
}

int random()
{
   time_t t;
   time(&t);
   srand((unsigned int)t);
   int x;
   x=rand();
   return x;
}

void signup()
{
    fstream f("Student.dat",ios::out|ios::binary|ios::app);
    cout<<"\n\n Sign up with all your details : ";
    s.getdata();
    int index=random();
    s.get_card(index);
    f.write((char*)&s,sizeof(s));
    f.close();
}


void student :: modify()
{
   int z,c;
   long int ph;
    char p[20],em[20];
    cout<<"\n\n Enter 1 to modify phone number : ";
    cout<<"\n\n Enter 2 to modify the email id : ";
    cout<<"\n\n Enter 3 to modify password : ";
    cout<<"\n\n\t Select a number : ";
    cin>>c;


    switch(c)
    {
        case 1: cout<<"\n\n Enter new phone number : ";
               cin>>ph;
               p1.get_phone(ph);
                break;
        case 2: cout<<"\n\n Enter new email id : ";
                cin>>em;
               strcpy(s.email_id,em);
               break;
        case 3: cout<<"\n\n Enter new password : ";
                cin>>p;
              strcpy(s.password,p);
                break;
        default: cout<<"\n\n Sorry! Enter a valid number.";
                break;
    }
}



void edit(int card)
{
    int flag=0;
    fstream f("Student.dat",ios::in|ios::out|ios::binary);
    char doyou;
    cout<<"\n\n Do you want to edit details on your card? (y/n)";
    cin>>doyou;
            if(doyou=='y' || doyou=='Y')
            {

                   int pos=0;
                    while(f.read((char*)&s,sizeof(s)))
                    {
                        pos=f.tellg();
                    if(card==s.ret_card())
                    {
                        s.modify();
                        f.seekg(pos-1*sizeof(s));
                        f.write((char*)&s,sizeof(s));
                        flag=1;
                        break;
                    }
                    }
                    if(flag==0)
                    {
                        cout<<"\n Please check your Card Number again. They don't match. ";

                    }

            }
            else
            {
               cout<<"\n Go ahead.";
            }
            f.close();
}

int figureout()
{

	time_t now = time(NULL);
	struct tm *now_s = localtime(&now);
	int t_code;


	if(now_s == NULL)
	return 0;

	if(now_s->tm_hour>1 && now_s->tm_hour<=11)
	{
		t_code=1;
	}

	else if(now_s->tm_hour>11 && now_s->tm_hour<=16 )
	{
		t_code=2;
	}

	else if(now_s->tm_hour>16 && now_s->tm_hour<=18 )
	{
		t_code = 3;

	}
	else
	{
		t_code =4;
	}
	return t_code;
}

class admin
{
    int price;
    char food_name[20];
    int code;
public:
    char username[20],passwordd[20];
    admin()
    {
        strcpy(username,"RUTVI");
        strcpy(passwordd,"12345");
    }
    void getd()
    {
        cout<<"\n Enter the Menu : ";
        cout<<"\n\n Enter the code number for the item here : ";
        cin>>code;
        cout<<"\n\n Enter the item here : ";
        cin>>food_name;
        cout<<"\n\n Enter its price here : Rs.";
        cin>>price;
    }

    void setmenu();
    void disp()
    {
        cout<<"\n\n  Code - "<<code;
        cout<<"\t  Food Item - "<<food_name;
        cout<<"\t  Price - Rs."<<price;

    }
    int ret_code()
    {
        return code;
    }
    int ret_price()
    {
        return price;
    }

}ad;


void admin :: setmenu()
{

       getd();
           int dummy= figureout();
           switch(dummy)
           {

       case 1: f1.open("breakfast.dat",ios::binary|ios::in|ios::out|ios::app);
                count2++;
                    f1.write((char*)&ad,sizeof(ad)); f1.close();
                    break;
           case 2: f2.open("lunch.dat",ios::binary|ios::in|ios::out|ios::app);
                    count2++;
                    f2.write((char*)&ad,sizeof(ad));f2.close();
                    break;

            case 3: f3.open("snacks.dat",ios::binary|ios::in|ios::out|ios::app);
                    count2++;
                    f3.write((char*)&ad,sizeof(ad));f3.close();
                    break;
            case 4: f4.open("dinner.dat",ios::binary|ios::in|ios::out|ios::app);
                    count2++;
                    f4.write((char*)&ad,sizeof(ad));f4.close();
                    break;
           }
}

void update(student q)
{
    student s;
    fstream fp("Student.dat",ios::out|ios::in);
    while((fp.read((char*)&s,sizeof(s))))
    {
    if(s.ret_card()==q.ret_card())
    {
        fp.seekp(fp.tellg()-1*sizeof(s));
        fp.write((char*)&q,sizeof(q));
    }

    }
    fp.close();

}




 void add_cash()
{
            char ans;
            int amt;

                cout<<"\n\n Do you want to input cash into your account? (y/n)";
                cin>>ans;
                    if(ans=='y' || ans=='Y')
                    {
                        cout<<"\n Enter the amount? ";
                        cin>>amt;
                        int z=s.ret_amt();
                        z+=amt;
                        s.get_amt(z);
                        update(s);
                    }
                    else
                    {
                        cout<<"\n Go ahead.";
                    }
}

void d_menu()
{
	time_t now = time(NULL);
	struct tm *now_s = localtime(&now);
	int t_code;
	if(now_s->tm_hour>1 && now_s->tm_hour<=11)
	{

	    f1.open("breakfast.dat",ios::binary|ios::in|ios::app);
	    while(f1)
        {
        if(!f1.read((char*)&ad,sizeof(ad)))
        {
           // cout<<"\n\n Sorry! There is nothing available for breakfast right now";
            break;
        }
        ad.disp();
        }
        f1.close();
	}

	else if(now_s->tm_hour>11 && now_s->tm_hour<=16 )
	{

		f2.open("lunch.dat",ios::binary|ios::in);
		f2.seekg(0);
	 while(f2)
      {
		if(!f2.read((char*)&ad,sizeof(ad)))
        {
             //cout<<"\n\n Sorry! There is nothing available for lunch right now";
              break;
        }
        ad.disp();
      }
        f2.close();
	}

	else if(now_s->tm_hour>16 && now_s->tm_hour<=18 )
	{

		f3.open("snacks.dat",ios::binary|ios::in|ios::app);
         f3.seekg(0);
         while(f3)
        {
       if(!f3.read((char*)&ad,sizeof(ad)))
       {
           // cout<<"\n\n Sorry! There is nothing available for snacks right now";
               break;
       }

        ad.disp();
        }
        f3.close();
	}
	else
	{

		f4.open("dinner.dat",ios::binary|ios::in|ios::app);
		 f4.seekg(0);
        while(f4)
        {

		if(!f4.read((char*)&ad,sizeof(ad)))
        {
           // cout<<"\n\n Sorry! There is nothing available for dinner right now";
               break;
        }
        ad.disp();
        }
        f4.close();
	}

}

void delete_s()
{
    int num;
    fstream fp1,fp2;
    fp1.open("Student.dat",ios::in|ios::binary);
    fp2.open("temp.dat",ios::binary|ios::out);
     while(fp1.read((char*)&s,sizeof(s)))
    {
        s.display();
    }
    cout<<"\n Enter card number that has to be deleted : ";
    cin>>num;
    while(fp1)
    {
        fp1.read((char*)&s,sizeof(s));
       if(num!=s.ret_card() && s.ret_card()!=0)
        {
           fp2.write((char*)&s,sizeof(s));
           s.reset();
        }
    }
    cout<<"\n The record has been deleted"<<endl;
    fp1.close();
    fp2.close();
    remove("Student.dat");
    rename("temp.dat","Student.dat");

}

void search_s()
{
    int cardnum;
    int flag=0;
    cout<<"\n\n Enter the card number of the student to be searched : ";
    cin>>cardnum;
    fstream file("Student.dat",ios::in|ios::binary);
    while(file)
    {
     if(!(file.read((char*)&s,sizeof(s))))
         break;
    if(cardnum==s.ret_card())
    {
        cout<<"\n Record found. Displaying the record ";
        s.display();
        flag=1;
    }

    }
     if(flag==0)

    cout<<"\n Sorry! Record not found.";
    file.close();
}


void purchase()
{
    int pick,flag1,flag2,flag3,flag4;
        char a;
    cout<<"\n\n Displaying the Menu ";
     cout<<"\n\n\t\t        MENU        ";
      d_menu();

                        int k=figureout();

                        if(k==1)
                        {   do
                            {
                            cout<<"\n\n Pick what you like. Enter its code here : ";
                           cin>>pick;


                                fstream f1;
                                f1.open("breakfast.dat",ios::binary|ios::in);
                            flag1=0;
                             while(f1)
                            {

                                f1.read((char*)&ad,sizeof(ad));
                                int t=ad.ret_code();
                            if(pick==t)
                            {
                                int l=s.ret_amt();
                                l=l-ad.ret_price();
                                if(l>0)
                                {
                                    code1[count1]=pick;
                                    count1++;

                                cout<<"\n\t Balance : "<<l;
                                s.get_amt(l);
                                update(s);
                                flag1=1;
                                break;
                                }
                                else
                                {
                                    cout<<"\n\n Sorry you don't have sufficient balance";
                                    cout<<"\n\n Use option 2 to add credit into the account";
                                      l+=ad.ret_price();
                                    s.get_amt(l);
                                    flag1=1;
                                    break;

                                }
                            }
                            }
                            if(!flag1)
                            cout<<"\n\t Sorrry! Invalid code.";

                            cout<<"\n\t Do you want to pick more?(y/n)";
                            cin>>a;
                            }while(a=='y' || a=='Y');
                             if(a=='n' || a=='N')
                                bill();


                        }
                        else if(k==2)
                        {
                            do
                            {
                            fstream f2("lunch.dat",ios::binary|ios::in);

                             cout<<"\n\n Pick what you like. Enter its code here : ";
                           cin>>pick;
                            while(f2)
                            {
                                f2.read((char*)&ad,sizeof(ad));

                            flag2=0;
                            if(pick==ad.ret_code())
                            {
                                int l=s.ret_amt();
                                l=l-ad.ret_price();
                                if(l>0)
                                {
                                    code1[count1]=pick;
                                    count1++;

                                    cout<<"\n\t Balance : "<<l;
                                  s.get_amt(l);
                                  update(s);
                                  flag2=1;
                                  break;
                                }
                                  else
                                {
                                    cout<<"\n\n Sorry you don't have sufficient balance";
                                    cout<<"\n\n Use option 2 to add credit into the account";
                                      l+=ad.ret_price();
                                    s.get_amt(l);
                                    flag2=1;
                                    break;

                                }
                            }
                            }

                            if(!flag2)
                            cout<<"\n\t Sory! Invalid code.";

                            cout<<"\n\t Do you want to pick more?(y/n)";
                            cin>>a;
                            }while(a=='y' || a=='Y');
                            if(a=='n' || a=='N')
                                bill();
                            f2.close();
                        }



                        else if(k==3)
                        {
                            do
                            {

                            fstream f3("snacks.dat",ios::binary|ios::in);
                             cout<<"\n\n Pick what you like. Enter its code here : ";
                           cin>>pick;

                            while(f3)
                            {

                                f3.read((char*)&ad,sizeof(ad));
                            flag3=0;
                            if(pick==ad.ret_code())
                            {
                                int l=s.ret_amt();
                                  l=l-ad.ret_price();
                                if(l>0)
                                {
                                     code1[count1]=pick;
                                    count1++;

                                cout<<"\n\t Balance : "<<l;
                                  s.get_amt(l);
                                  update(s);
                                  flag3=1;
                                  break;
                                }
                                else
                                {
                                    cout<<"\n\n Sorry you don't have sufficient balance";
                                    cout<<"\n\n Use option 2 to add credit into the account";
                                      l+=ad.ret_price();
                                    s.get_amt(l);
                                    flag3=1;
                                    break;

                                }
                            }
                            }
                            if(!flag3)
                            cout<<"\n\t Sorry! Incorrect code.";

                            cout<<"\n\t Do you want to pick more? (y/n)";
                            cin>>a;
                              f3.close();
                            }while(a=='y' || a=='Y');
                             if(a=='n' || a=='N')
                                bill();

                        }





                      else if(k==4)
                        {
                            do
                            {
                            fstream f4("dinner.dat",ios::binary|ios::in);
                             cout<<"\n\n Pick what you like. Enter its code here : ";
                             cin>>pick;
                         while(f4.read((char*)&ad,sizeof(ad)))
                            {

                            flag4=0;
                            if(pick==ad.ret_code())
                            {

                                int l=s.ret_amt();
                             l=l-ad.ret_price();
                             if(l>0)
                                {
                                     code1[count1]=pick;
                                    count1++;

                                cout<<"\n\t Balance : "<<l;
                                  s.get_amt(l);
                                  update(s);
                                  flag4=1;
                                  break;
                                }
                                else
                                {
                                     cout<<"\n\n Sorry you don't have sufficient balance";
                                    cout<<"\n\n Use option 2 to add credit into the account"<<endl;
                                    flag4=1;
                                    l+=ad.ret_price();
                                    s.get_amt(l);

                                    break;
                                }
                            }

                            }
                            if(!flag4)
                            cout<<"\n\t Sorry! Incorrect code.";

                            cout<<"\n\t Do you want to pick more?(y/n)";
                            cin>>a;
                            f4.close();
                            }while(a=='y' || a=='Y');
                             if(a=='n' || a=='N')
                                bill();

                        }

}
int get_size(char q[20]){

        ifstream f(q);
        f.seekg(0,ios::end);
        int size = f.tellg();
        return size/sizeof(admin);
}

void bill()
{
    system("cls");
    int total=0,track,prices;string names;
    int dum=figureout();
    cout<<"\n\n\t\t\t    BILL  ";
    cout<<"\n\n**********************************************************";

        if(dum==1)
    {
        ifstream brk("breakfast.dat",ios::binary);
        for(int gg=0;gg<get_size("breakfast.dat");gg++)
        {
            brk.read((char*)&ad,sizeof(ad));
            for(i=0;i<count1;i++)
            {
                if(ad.ret_code()==code1[i])
                {
                    ad.disp();
                    total+=ad.ret_price();
                }
            }
        }
        cout<<"\n\n\t Total Amount payable : "<<total;
        cout<<"\n\n**********************************************************";
    }

    if(dum==2)
    {
        ifstream lun("lunch.dat",ios::binary);
        for(int gg=0;gg<get_size("lunch.dat");gg++)
        {
            lun.read((char*)&ad,sizeof(ad));
            for(i=0;i<count1;i++)
            {
                if(ad.ret_code()==code1[i])
                {
                    ad.disp();
                    total+=ad.ret_price();
                }
            }
        }
        cout<<"\n\n\t Total Amount payable : "<<total;
        cout<<"\n\n**********************************************************";
    }

        if(dum==3)
    {
        ifstream snak("snacks.dat",ios::binary);
        for(int gg=0;gg<get_size("snacks.dat");gg++)
        {
            snak.read((char*)&ad,sizeof(ad));
            for(i=0;i<count1;i++)
            {
                if(ad.ret_code()==code1[i])
                {
                    ad.disp();
                    total+=ad.ret_price();
                }
            }
        }
        cout<<"\n\n\t Total Amount payable : "<<total;
        cout<<"\n\n**********************************************************";
    }

        if(dum==4)
    {
        ifstream din("dinner.dat",ios::binary);
        for(int gg=0;gg<get_size("dinner.dat");gg++)
        {
            din.read((char*)&ad,sizeof(ad));
            for(i=0;i<count1;i++)
            {
                if(ad.ret_code()==code1[i])
                {
                    ad.disp();
                    total+=ad.ret_price();
                }
            }
        }
        cout<<"\n\n\t Total Amount payable : "<<total;
        cout<<"\n\n**********************************************************";
    }
}



void all_fns(int opt)
{

fstream f;
f.open("Student.dat",ios::in|ios::binary);

                    if(opt==1)
                    {
                        cout<<"\n\n You have Rs. "<<s.ret_amt()<<" left in your card"<<endl;
                        if(s.ret_amt()>0)
                        {
                             purchase();
                        }

                    }
                    else if (opt==2)
                    {
                        cout<<"\n\n You currently have Rs."<<s.ret_amt()<<" in your account"<<endl;
                         add_cash();
                         s.display();
                    }
                    else if(opt==3)
                    {
                         edit(card);
                         s.display();
                        // system("cls");
                    }
                    else if(opt==4)
                    {
                        cout<<"\n\t Remaining balance : Rs.";
                        int g=s.ret_amt();
                        cout<<g<<"\n";
                        cout<<"\n\n Amount can be collected from the Admin "<<endl;
                    }

                    f.close();
}




int main()
{

    int choice,opt,op;
    int pick,l;
    int flaglogin=0;
    fstream f;

        // First page
    label:

    cout<<"\n\n\t********************************************";
    cout<<"\n                   WELCOME";
    cout<<"\n\t********************************************";
    cout<<"\n\t1.Sign up";
    cout<<"\n\t2.Student Login";
    cout<<"\n\t3.Admin Login";
    cout<<"\n\t********************************************";

    cout<<"\n\n Enter choice : ";
    cin>>choice;
    char a,answer='y',v;
    switch(choice)
    {
        case 1: cout<<"\n\t SIGN UP ";
                signup();
                s.display();
                break;
        case 2: q:
                cout<<"\n\n\t STUDENT LOGIN ";
                cout<<"\n\t Enter username/card number : ";
                cin>>card;
                cout<<"\n\t Enter your Password (4-digit number) : ";
                int kk;
                 kk=0;char c;
                 while(kk!=4)
                 {
                     c=getch();
                     pass[kk]=c;
                     kk++;
                     cout<<'*';
                 }

                pass[kk]='\0';

                f.close();
                f.open("Student.dat",ios::in|ios::binary);
            f.seekg(0);

            flaglogin=0;
            while(f.read((char*)&s,sizeof(s)))
            {

                if((card==s.ret_card()) && (strcmp(pass,s.password)==0))
                {
                   t:
                        flaglogin=1;
                        system("cls");
                        cout<<"\n\n\t********************************************";
                        cout<<"\n\t 1.Purchase food";
                        cout<<"\n\t 2.Add cash";
                        cout<<"\n\t 3.Edit details";
                        cout<<"\n\t 4.Cash back option";
                        cout<<"\n\t 5.Logout";
                        cout<<"\n\n\t ********************************************";
                        cout<<"\n\n  Enter option : ";
                        cin>>opt;
                        if (opt==5)
                        {
                        cout<<"\n\t Logging out.";
                        system("cls");
                        goto label;
                        }
                        all_fns(opt);

                        cout<<"\n\n\n\tDo you want to select another option? (y/n)";
                        cin>>answer;
                        if(answer=='y' || answer=='Y')
                        {
                            system("cls");
                            goto t;
                        }
                    }
                }
                 if(flaglogin==0)
                   {
                       char o;
                       cout<<"\n Sorry. Invalid Card Number/Password. Try again? Enter y/n :)";
                       cin>>o;
                       if(o=='y' || o=='Y')
                       {
                           system("cls");
                            goto q;
                       }
                       else if(o=='n')
                       {
                            system("cls");
                           goto label;
                       }
                   }

                    system("cls");
                break;
        case 3: cout<<"\n\n\t ADMINISTRATOR LOGIN ";
                cout<<"\n\t Enter Admin username : ";
                cin>>user;
                cout<<"\n\t Enter password : ";
                 int pp;
                 pp=0;char c1;
                 while(pp!=5)
                 {
                     c1=getch();
                     passw[pp]=c1;
                     pp++;
                     cout<<'*';
                 }

                passw[pp]='\0';

                if(strcmp(user,ad.username)==0 && strcmp(passw,ad.passwordd)==0)
                {
                    lab:
                       system ("cls");
                     cout<<"\n\n\t********************************************";
                    cout<<"\n\t 1.Set menu";
                    cout<<"\n\t 2.Search student record";
                    cout<<"\n\t 3.View files";
                    cout<<"\n\t 4.Delete student record";
                    cout<<"\n\t 5.Logout";
                     cout<<"\n\t ********************************************";
                    cout<<"\n\n Enter option : ";
                    cin>>op;
                    if(op==1)
                    {
                        cout<<"\n\n\t\t MENU";
                        d_menu();
                       char ch;
                        do
                        {
                            ad.setmenu();
                            cout<<"\n\t Do you Want to add more to the menu? (y/n)";
                            cin>>ch;
                        }while(ch=='y' || ch=='Y');
                    }
                    else if(op==2)
                    {
                        search_s();
                    }
                    else if(op==3)
                    {
                       cout<<"\n\t Displaying all Student Files ";
                        fstream f("Student.dat",ios::binary|ios::in);
                        while(f.read((char*)&s,sizeof(s)))
                        {
                       //f.read((char*)&s,sizeof(s));
                            s.display();
                        }

                    }
                    else if(op==4)
                    {
                        delete_s();
                    }

                    else if(op==5)
                    {
                        cout<<"\nLogging out.";
                        system("cls");


                        goto label;
                    }
                    cout<<"\n\t Do you want to still continue? (y/n)";
                    cin>>v;
                    if(v=='y' || v=='Y')
                       {
                           system("cls");
                           goto lab;
                       }
                    else if(v=='n')
                    {
                        system("cls");
                        goto label;
                    }

                }
                else
                {
                    cout<<"\n\t Sorry! Admin password/username incorrect";
                }
                break;
        default: cout<<"\n\t Enter valid option.";
    }
    goto label;
    f.close();

    return 1;
}







