    //filename: Kmer.cpp
    #include <vector>
    #include <iostream>
    #include <string>
    #include <chrono>
    using namespace std::chrono;
    using namespace std;
    
    class Kmer {
        public:
            int len_str;      
	    string opt = "";
	    string s = "";
	    string s_last = "";
	    bool change_next;
	    
                    
            Kmer(int number_of_kmer){
            	//constructor
            	len_str = number_of_kmer;
		     opt = "ACGT";
		     s = "";
		     s_last = "";
		    
            }
            
            void calculate_Kmer(){
            
            		//get the time at the start
            	auto start = high_resolution_clock::now();
            
            	    for (int i=0; i<len_str; i++)
		    {
			s += opt[0];
		    }

		    for (int i=0; i<len_str; i++)
		    {
			s_last += opt.back();
		    }

		   
		    unsigned long counter = 1;
		    while (s != s_last)
		    {   
			counter ++;
			// You can uncomment the next line to see all k-mers.
			// cout << s << endl;  
			change_next = true;
			for (int i=0; i<len_str; i++)
			{
			    if (change_next)
			    {
				if (s[i] == opt.back())
				{
				    s[i] = convert(s[i]);
				    change_next = true;
				} else {
				    s[i] = convert(s[i]);
				    break;
				}
			    }
			}
		    }
		   
		   // Get ending timepoint
    		auto stop = high_resolution_clock::now();
		    
		cout << "Number of generated k-mers: " << counter << endl;
    		cout << "Finish!" << endl;
            	auto duration = duration_cast<seconds>(stop - start);
  		cout << duration.count() << " seconds" << endl;
  
            }
            
            	char convert(char c)
		{
		    if (c == 'A') return 'C';
		    if (c == 'C') return 'G';
		    if (c == 'G') return 'T';
		    if (c == 'T') return 'A';
		    return ' ';
		}
			    
            
           
    };

   int main(int argc,char* argv[]){
   
   //creating object of kmer
   cout<<"Generating "<<argv[1]<<" kmers "<<endl;
   int a = stoi(argv[1]);
   
   Kmer k(a);
   
   k.calculate_Kmer();
   
   return 0;
   }
