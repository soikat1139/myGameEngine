

#include<iostream>

#include<algorithm>


#include<vector>
#include<map>




typedef std::map<std::string, std::vector<int>> EntityMap;


bool func(int x){ 
        return x % 2 ==0;
    }

int main(){


    EntityMap entitymap;

    entitymap["hello"].push_back(5);
    entitymap["hello"].push_back(6);
    entitymap["hello"].push_back(7);
   

    for(auto& [tag,vec]:entitymap){
        for(auto& e : vec){
            std::cout<<e<<std::endl;
        }
    }

 


    bool (*ptr)(int );

    ptr=&func;


    std:: vector<int> v={1,2,3,4,5,6,7,8,9,10};
    


    auto toRemove=std::remove_if(v.begin(),v.end(),ptr);


    v.erase(toRemove,v.end());

    for(auto e : v){

        std::cout<<e<<std::endl;
    }

  
















    return 0;
}

 
