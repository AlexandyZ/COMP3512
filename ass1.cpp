#include "student.h"

using namespace std;

int main(int argc, char* argv[]) {
	vector<Student> v;
	Student s;
    string str;
    string cmd[4];
    int lsc, hsc;
    
    //read the file
    if(argc != 2) {
        cerr << "usage: " << argv[0] << "record" << endl;
        exit(1);
    }
    else {
        ifstream fs(argv[1]);
        if(!fs) {
            cerr << "unable to open the file";
            exit(1);
        } else {
            while( fs >> s)
                v.push_back(s);
        }
    }
	
    //read the commands
	while (getline(cin, str)) {
        //no command
		istringstream iss(str);
		if (!(iss >> cmd[0]))
			cout << endl;
        //read first command
		else if (cmd[0] == "show") {
			sort(v.begin(), v.end(), Cmp("as"));
            //read second, third commands
			if (!(iss >> cmd[1] >> cmd[2])) {
				for (auto& x: v)
					x.display(cout);
			}
            //compare the second command
			else if (cmd[1] == "id") {
				IdFinder idf = for_each(v.begin(), v.end(), IdFinder(cmd[2]));
				for (auto it = idf.v.begin(); it != idf.v.end(); ++it)
					it->display(cout);
			}
            else if (cmd[1] == "name") {
                if(!(iss >> cmd[3]))
                    cout << endl;
				NameFinder nf = for_each(v.begin(), v.end(), NameFinder(cmd[2], cmd[3]));
				for (auto it = nf.v.begin(); it != nf.v.end(); ++it)
					(*it).display(cout);
		    }
            else if (cmd[1] == "grade") {
                if(!(iss >> lsc))
                    cout << endl;
                else if(!(iss >> hsc)){
                    GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it)
						it->display(cout);
                }
                else {
					GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc, hsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it) {
						it->display(cout);
					}
				}
			}
		}
		else if (cmd[0] == "-show") {
			sort(v.begin(), v.end(), Cmp("ds"));
			if (!(iss >> cmd[1] >> cmd[2])) {
				for (auto& x : v)
					x.display(cout);
			}
            else if (cmd[1] == "id") {
				IdFinder idf = for_each(v.begin(), v.end(), IdFinder(cmd[2]));
				for (auto it = idf.v.begin(); it != idf.v.end(); ++it)
					it->display(cout);
			}
            else if (cmd[1] == "name") {
                if(!(iss >> cmd[3]))
                    cout << endl;
				NameFinder nf = for_each(v.begin(), v.end(), NameFinder(cmd[2], cmd[3]));
				for (auto it = nf.v.begin(); it != nf.v.end(); ++it)
					(*it).display(cout);
		    }
            else if (cmd[1] == "grade") {
                if(!(iss >> lsc))
                    cout << endl;
                else if(!(iss >> hsc)){
                    GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it)
						it->display(cout);
                }
                else {
					GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc, hsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it) 
						it->display(cout);
				}
			}			
		}
		else if (cmd[0] == "-showid") {
			sort(v.begin(), v.end(), Cmp("ds"));
			if (!(iss >> cmd[1] >> cmd[2])) {
				for (auto& x : v)
					x.displayId(cout);
			}
			else if (cmd[1] == "id") {
				IdFinder idf = for_each(v.begin(), v.end(), IdFinder(cmd[2]));
				for (auto it = idf.v.begin(); it != idf.v.end(); ++it)
					it->displayId(cout);
			}
            else if (cmd[1] == "name") {
                if(!(iss >> cmd[3]))
                    cout << endl;
				NameFinder nf = for_each(v.begin(), v.end(), NameFinder(cmd[2], cmd[3]));
				for (auto it = nf.v.begin(); it != nf.v.end(); ++it)
					(*it).displayId(cout);
		    }
            else if (cmd[1] == "grade") {
                if(!(iss >> lsc))
                    cout << endl;
                else if(!(iss >> hsc)){
                    GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it)
						it->displayId(cout);
                }
                else {
					GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc, hsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it)
						it->displayId(cout);
				}
			}
		}
		else if (cmd[0] == "showid") {
			sort(v.begin(), v.end(), Cmp("as"));
			if (!(iss >> cmd[1] >> cmd[2])) {
				for (auto& x : v) {
					x.displayId(cout);
				}
			}
			else if (cmd[1] == "id") {
				IdFinder idf = for_each(v.begin(), v.end(), IdFinder(cmd[2]));
				for (auto it = idf.v.begin(); it != idf.v.end(); ++it)
					it->displayId(cout);
			}
            else if (cmd[1] == "name") {
                if(!(iss >> cmd[3]))
                    cout << endl;
				NameFinder nf = for_each(v.begin(), v.end(), NameFinder(cmd[2], cmd[3]));
				for (auto it = nf.v.begin(); it != nf.v.end(); ++it)
					(*it).displayId(cout);
		    }
            else if (cmd[1] == "grade") {
                if(!(iss >> lsc))
                    cout << endl;
                else if(!(iss >> hsc)){
                    GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it)
						it->displayId(cout);
                }
                else {
					GradeFinder gf = for_each(v.begin(), v.end(), GradeFinder(cmd[2], lsc, hsc));
					for (auto it = gf.v.begin(); it != gf.v.end(); ++it)
						it->displayId(cout);
				}
			}
		}
		cout << endl;
	}
}

