#include<bits/stdc++.h>
using namespace std;

class Movie{
    string name;
    string genre;
    string language;
    string release_date;
    public:
    Movie()=default;
    Movie(string n,string g,string l,string r){
        name=n;
        genre=g;
        language=l;
        release_date=r;

    };
    string get_name(){
        return this->name;

    }
    
     string get_genre(){
        return this->genre;

    }
    
    string get_lang(){
        return this->language;

    }
    
    string get_date(){
        return this->release_date;

    }
    void show_movie(){
        cout<<" Title: "<<this->name<<endl;
        cout<<" Genre: "<<this->genre<<endl;
        cout<<" Release Date "<<this->release_date<<endl;
        cout<<" Language: "<<this->language<<endl;
        cout<<"--------------------"<<endl;
    }

};

class Halls {
   Movie movie;
   int capacity;
   vector<int> seats;
   public:
   Halls()=default;
   Halls(int c){
       capacity=c;
   };
   void set_hall(){
     for(int i=0;i<capacity;i++){
         seats.push_back(0);

     }

   }
   //function to book seats
   void book_seat(int no){
       if(no>capacity){
           cout<<"Please enter a valid seat number ranging from 1 to "<<capacity<<endl;
       }
       else{
          no--;
          if(seats[no]==0){
           seats[no]=1;
           cout<<"Seat is booked"<<endl;

            }
           else{
               cout<<"This seat is not available please see avaliable seats"<<endl;
               cout<<"To see available seat enter show_seats"<<endl;
           } 

       }
      
   }
   //showing all the seats 
   void show_seats(){
       cout<<"Seats with 0 are avaliable for booking and seats with 1 are occupied : "<<endl;
       for(int i=0;i<capacity;i++){
           cout<<" -> Seat No: "<<i+1<<" : "<<seats[i]<<endl;
       }
       bool full=true;
       for(int i=0;i<capacity;i++){
           if(seats[i]==0){
               full=false;
               break;
           }
       }
       if(full){
           cout<<"This Hall is fully occupied"<<endl;
       }
       else{
           cout<<"Seats are available"<<endl;
       }
   }
   void set_movie(Movie m){
       this->movie=m;

   }
    Movie get_movie(){
       return this->movie;

   }
   
   int get_capacity(){
       return capacity;
   }
  



};

class Cinema{
  string name;
  vector<Halls> hall;
  public:
  void addHall(Halls halls){
      this->hall.push_back(halls);

  }
  void show_halls(){
      int n=this->hall.size();
      for(int i=0;i<n;i++){
          cout<<"Hall No: "<<i+1<<endl;
          cout<<"-----------------"<<endl;
          Movie m= hall[i].get_movie();
          m.show_movie();
      }
  }
 
  
  vector<Halls> get_halls(){
      int n=this->hall.size();
      
      return this->hall;

  }
  
  void set_name(string nm){
      this->name=nm;

  }
  string get_name(){
      return this->name;
      
  }
  Cinema(){};
 // friend class Cities;



};

class Cities{
 string name;
 vector<Cinema> cinema;
 public:
 Cities(){};
 void set_name(string n){
     this->name=n;

 }
 string get_name(){
     return name;
 }

 

 void addcinema(Cinema cin){
     
     this->cinema.push_back(cin);
    
    


 }
 //Cinemas in the city
 void show_cinema(){
     int n=this->cinema.size();
     cout<<"Cinemas in "<<this->name<<": "<<endl;
     for(int i=0;i<n;i++){
         string x=cinema[i].get_name();
         cout<<" ->"<<x<<endl;
     }
 }
 void show_titles(){
      int n=this->cinema.size();
      for(int i=0;i<n;i++){
         string x=cinema[i].get_name();
         cout<<"Movies in  "<<x<<endl;
         vector<Halls> h=cinema[i].get_halls();
         int n1=h.size();
         for(int j=0;j<n1;j++){
             Movie m=h[j].get_movie();
             m.show_movie();
         }
     }

 }
 void search_title(string s){
     int n=this->cinema.size();
     cout<<s<<" in "<<this->name<<" :"<<endl;
     bool none=true;
      for(int i=0;i<n;i++){
         string x=cinema[i].get_name();
        
         vector<Halls> h=cinema[i].get_halls();
         int n1=h.size();
         
         for(int j=0;j<n1;j++){
             Movie m=h[j].get_movie();
             string y=m.get_name();
             if(y==s){
                 none=false;
                 cout<<"In "<<x<<" Cinema: "<<endl;
                 m.show_movie();
             }
         }
        
     }
      if(none){
             cout<<"No such movie found"<<endl;
         }

 }
 void search_genre(string s){
     int n=this->cinema.size();
     cout<<s<<" movies in "<<this->name<<" :"<<endl;
     bool none=true;
      for(int i=0;i<n;i++){
         string x=cinema[i].get_name();
        
         vector<Halls> h=cinema[i].get_halls();
         int n1=h.size();
          
         for(int j=0;j<n1;j++){
             Movie m=h[j].get_movie();
             string y=m.get_genre();
             if(y==s){
                 none=false;
                 cout<<"In "<<x<<" Cinema: "<<endl;
               
                 m.show_movie();
             }
         }
        
         

     }
      if(none){
             cout<<"No such movie found"<<endl;
         }

 }
 void search_lang(string s){
     int n=this->cinema.size();
     cout<<s<<" language movies in "<<this->name<<" :"<<endl;
      bool none=true;
      for(int i=0;i<n;i++){
         string x=cinema[i].get_name();
        
         vector<Halls> h=cinema[i].get_halls();
         int n1=h.size();
        
         for(int j=0;j<n1;j++){
             Movie m=h[j].get_movie();
             string y=m.get_lang();
             if(y==s){
                 none=false;
                 cout<<"In "<<x<<" Cinema: "<<endl;
                 m.show_movie();
             }
         }
        
     }
    if(none){
             cout<<"No such movie found"<<endl;
         }

 }

};

int main(){
    
   cout<<"TICKET MASTER"<<endl;
    Cities cityA;
    cityA.set_name("Delhi");
    Cinema c1;
    c1.set_name("Cinepolis");
    Halls h1(10);
   
    Movie m1("Venom2","Sci-fi","English","1/10/2019");
    
    h1.set_movie(m1);

    Halls h2(8);
   
    Movie m2("Venom","Sci-fi","English","1/10/2018");
    
    h2.set_movie(m2);
    c1.addHall(h1);
    c1.addHall(h2);
    Cinema c2;
    c2.set_name("PVR");
    Halls hh1(5);
    Movie m3("Shang-Chi","Sci-fi","English","10/10/2021");
   
   
    hh1.set_movie(m3);
    h1.set_hall();
    h2.set_hall();
    hh1.set_hall();
    h1.book_seat(5);
    h1.show_seats();
    h1.book_seat(18);
    c2.addHall(hh1);
    c1.show_halls();
    cityA.addcinema(c1);
    cityA.addcinema(c2);
    cityA.show_cinema();
    cityA.show_titles();
   // cityA.search_title("Venom");
   // cityA.search_genre("romance");
    //cityA.search_lang("English");

  
   return 0;
}