#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define pi 3.14159265358979323846
using namespace std;

int length(double a, double b, double c){
    int val = 0 ;

    for(int i=a;i<=c;i+=b){
        val++;
    }   

    return val;
}

void createArray(double arr[], double a, double b, double c){
    int val = 0;
    for(int i=a;i<=c;i+=b){
        arr[val++] = i;
    }
}

vector<vector<double>> physical_param(){
    double g= 9.81;
    double m=330;          
    double rwb=0.55;        
    double wheelbase=1.5495; 
    double a = wheelbase*rwb;          
    double b = wheelbase*(1-rwb);

    double massdist_array[4];

    massdist_array[0] = g;
    massdist_array[1] = rwb;
    massdist_array[2] = a;
    massdist_array[3] = b;

    double rho=1.225;          
    double cl=5; 
    double aero_balance=0.60; 
    double cd=1; 

    double aero_array[4];

    aero_array[0] = rho;
    aero_array[1] = cl;
    aero_array[2] = cd;
    aero_array[3] = aero_balance;

    double mns_front=18;                      
    double mns_rear=22;                       
    double ms_front=m*(1-rwb)-mns_front;      
    double ms_rear=m*rwb-mns_rear;

    double mass_array[5];

    mass_array[0] = m;
    mass_array[1] = mns_front;
    mass_array[2] = mns_rear;         
    mass_array[3] = ms_front;
    mass_array[4] = ms_rear;  

    double cg_array[5];

    double com=0.3; 
    double com_fns=0.2286;     
    double com_rns=0.2286;     
    double com_fs=(com*m*(1-rwb)-com_fns*mns_front)/ms_front;  
    double com_rs=(com*m*rwb-com_rns*mns_rear)/ms_rear;   

    cg_array[0]=com;
    cg_array[1]=com_fns;
    cg_array[2]=com_rns;
    cg_array[3]=com_fs;
    cg_array[4]=com_rs;

    double kf_spring=45000;  
    double kr_spring=45000;  
    double motionratio_front=1.1;   
    double motionratio_rear=1.1;
    double kf_arb=36533;   
    double kr_arb=32520;    
    double motionratio_frontarb=1.85;  
    double motionratio_reararb=1.9;     
    double twf=1.2;     
    double twr=1.25;      
    double rc_f=0.0135;      
    double rc_r=0.0141;

    double length_array[5];

    length_array[0] = wheelbase;
    length_array[1] = twf;
    length_array[2] = twr;    
    length_array[3] = rc_f;
    length_array[4] = rc_r;

    double KPI=        16.1552529*pi/180;      
    double CA =        2.591582694*pi/180;     
    double scrub=     (16.84898008)/1000;      
    double cast_trl=  (5.223596862)/1000;   

    double steering_array[4];

    steering_array[0] = KPI;
    steering_array[1] = CA;
    steering_array[2] = scrub;    
    steering_array[3] = cast_trl;

    double whr_front=(kf_spring/(motionratio_front*motionratio_front));      
    double whr_rear=(kr_spring/(motionratio_rear*motionratio_rear));  

    double derived_const[5];
    double whr_front=(kf_spring/motionratio_front*motionratio_front);      
    double whr_rear=(kr_spring/motionratio_rear*motionratio_rear);       

    double arbwh_front = (kf_arb/(motionratio_frontarb*motionratio_frontarb));  
    double arbwh_rear=(kr_arb/(motionratio_reararb*motionratio_reararb));  
    double K_tire = 157000; 
    double antiroll_stiffness_front=0.5*(twf*twf*(K_tire*(whr_front+arbwh_front)/(K_tire+whr_front+arbwh_front)));    
    double antiroll_stiffness_rear=0.5*(twr*twf*(K_tire*(whr_rear+arbwh_rear)/(K_tire+whr_rear+arbwh_rear)));      
    double lam=antiroll_stiffness_front/(antiroll_stiffness_front+antiroll_stiffness_rear);
    derived_const[0]=whr_front;
    derived_const[1]=whr_rear;
    derived_const[2]=antiroll_stiffness_front;
    derived_const[3]=antiroll_stiffness_rear;
    derived_const[4]=antiroll_stiffness_front+antiroll_stiffness_rear;

    vector<vector<double>> array;

    array.push_back(vector<double>(massdist_array, massdist_array+6));
    array.push_back(vector<double>(mass_array, mass_array+5));
    array.push_back(vector<double>(cg_array, cg_array+5));
    array.push_back(vector<double>(aero_array, aero_array+4));
    array.push_back(vector<double>(length_array, length_array+5));
    array.push_back(vector<double>(steering_array, steering_array+4));
    array.push_back(vector<double>(derived_const, derived_const+5));
    return array;
}



void gg(double res[], double val){

    

}

int main(){

    int k = length(7,1,24);
    double v[k];
    createArray(v,7,1,24);

    for(int i=0;i<k;i++){
        cout<<v[i]<<" ";
    }

    for(int i=0;i<k;i++){
        cout<<i<<endl;



    }
}