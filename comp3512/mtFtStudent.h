class mtFtStudent:public mtStudent{
private:
	string program_;
	static int count_;

public:
	mtFtStudent(const std::string& id, 
				const std::string& firstname, 
				const std::string& lastname, 
				const std::string& program)
	:id_(id), name_(firstname, lastname), program_(program){count_++;}
	mtFtStudent(const mtFtStudent& src):mtStudent(src),program_(src.program_){count_++;}
	~mtFtStudent(){count_--;}
	explicit mtFtStudent(std::istream& is):mtStudent(is){

	}

	void save(std::ostream& os)const{
		mtStudent::save(os);

		os<<(mtStudent&) mtFtStudent << std::endl;
		os << program_;
	}	
	void 
	
}