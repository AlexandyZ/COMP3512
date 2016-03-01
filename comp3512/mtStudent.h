typedef Name<string,string> Name;
typedef Course<string, int> Course;

class mtStudent{
private:
	vector<Course> courses_;
	string id_;
	Name name_;

public:
	mtStudent(const std::string& id, 
		const std::string& firstname, 
		const std::string& lastname)
	:id_(id), name_(firstname, lastname){}

	explicit mtStudent(std::istream& is){

	}

	void save(ostream& os)const{
		os << id_ << endl;
		os << name_ << endl;
		os << courses_.size() << endl;
		for(auto it : Course){
			os<< it->first >> ' ' >> it-> second << std::endl;
		}
	}	

}