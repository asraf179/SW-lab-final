#include<bits/stdc++.h>
#include"gtest/gtest.h"
using namespace std;


class StudentManager{
    private:
    static StudentManager* studentmanager;
    vector<string>students;
    int count=0;
     StudentManager(){
        cout<<"instantiated"<<endl;
     }
    public:
    static StudentManager* getinstance(){
        if(studentmanager==nullptr)
           studentmanager=new StudentManager();
        return studentmanager;
    }
    void add (string name){
        students.push_back(name);
        count++;
    }
    void remove(string name){
        for (int i=0;i<students.size();i++){
            if(students[i]==name){
                string s=students[i];
                string m=students[count-1];
                students[i]=m;
                students[count-1]=s;
                students.pop_back();
            }
        }
    }
    int getStudentNumber(){
        return count;
    }
    void display(){
        cout<<"All students"<<endl;
        for(int i=0;i<students.size();i++){
            cout<<students[i]<<endl;
        }
    }

};
StudentManager* StudentManager::studentmanager = nullptr;
int main(){
    StudentManager* studentmanager=StudentManager::getinstance();
    studentmanager->add("asraf");
    studentmanager->add("rifat");
    studentmanager->add("asif");
    studentmanager->add("shaon");
    studentmanager->add("sadik");
    studentmanager->remove("asif");
    studentmanager->display();


}