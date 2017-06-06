#ifndef STATUS_CODE_H
#define STATUS_CODE_H
#include <string>
#include <stdexcept>
#include <exception>

class UncheckedStatusCode: public std::exception {
public:
	UncheckedStatusCode() {}
	virtual const char* what() throw() {
		return "UncheckedStatusCode";
	}
};

class UncheckedStausHandler {
public:
	static void handle() {
	}
};

class StatusCode {
public:
	StatusCode(const StatusCode& stat_code)
		: _str_error_status (stat_code.info())
		, _b_error_status (stat_code.isok())
		, _isok (1)
	{}
	StatusCode(std::string error_status)
		: _str_error_status (error_status)
		, _b_error_status (0)
		, _isok (1)
	{}
	StatusCode()
		: _b_error_status (1)
		, _isok (1)
	{}
	static StatusCode& ALLOK() {
		return *(new StatusCode());
	}
	static StatusCode& ERROR(std::string error_status) {
		return *(new StatusCode(error_status));
	}
	bool isok() const {
		_isok = 0;
		return _b_error_status;
	}
	std::string info() const {
		return _str_error_status;
	}
protected:
	std::string _str_error_status;
	bool _b_error_status;
	mutable bool _isok;
};



#endif // STATUS_CODE_H