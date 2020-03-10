#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>

int string_to_int(std::string str){
	int res=0;
	for(unsigned int i=0;i<str.size();i++){
		res+=(static_cast<int>(str[i])-48)*pow(10,str.size()-i-1);
	}
	return res;
}

std::vector<int> split(const std::string &str, char d){
    std::vector<int> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos){
        r.push_back(string_to_int(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(string_to_int(str.substr(start)));

    return r;
}

void print_ip(std::vector<std::vector<int>> temp){
	for(const auto& t: temp){
	   	for(unsigned int i=0;i<t.size();i++){
			if(i!=0)
				std::cout<<".";
			std::cout<<t[i];
		}
	   	std::cout<<"\n";
	}
}


int main() {
	try{
	        std::vector<std::vector<int>> ip_pool, one_first, starts_with_46_70, any_46;
	        std::ifstream in("/home/dmitry/eclipse-workspace/ip_sort/src/ip_filter-12995-758870.tsv");
	        std::string temp;
	        for(std::string line; std::getline(in, line);){
	        	if(line=="")
	        		break;
	            std::string v = line.substr(0,line.find_first_of('\t'));
	            ip_pool.push_back(split(v, '.'));

	        }
	        sort(ip_pool.begin(), ip_pool.end(),[](std::vector<int> one, std::vector<int> two){
	        	for(unsigned int i=0;i<one.size();i++){
	        		if(one[i]==two[i])
	        			continue;
	        		else
	        			return one[i]>two[i];
	        	}
	        	return false;
	        });

	        for(const auto& s: ip_pool){
	        	if(s[0]==1)
	        		one_first.push_back(s);
	        	if(s[0]==46 && s[1]==70)
	        		starts_with_46_70.push_back(s);
	        	if(s[0]==46 || s[1]==46 || s[2]==46 || s[3]==46)
	        		any_46.push_back(s);

	        	for(unsigned int i=0;i<s.size();i++){
	        		if(i!=0)
	        			std::cout<<".";

	        		std::cout<<s[i];
	        	}
	        	std::cout<<std::endl;
	        }

	      print_ip(one_first);
	      print_ip(starts_with_46_70);
	      print_ip(any_46);

	    }catch(const std::exception &e){
	        std::cerr << e.what() << std::endl;
	    }

	return 0;
}
