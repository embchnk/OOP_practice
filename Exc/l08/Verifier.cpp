
#include "Verifier.h"

int ArgVerificationFailed::arg = 0;
std::string ArgVerificationFailed::status = "";
std::string ArgVerificationFailed::name = " ";

 std::string concat(const char* msg, int val) {
  std::ostringstream oss;
  oss << msg << " " << val;
  return oss.str();
}
/*************************************************************/
ArgVerificationFailed::ArgVerificationFailed(int argument, std::string error_status) {
	arg = argument;
	status = error_status;
}
/*************************************************************/
std::ostream& operator<<(std::ostream& out, const ArgVerificationFailed& object) {
	out << "Argument " << ArgVerificationFailed::arg << " " << ArgVerificationFailed::status;
	return out;
}
/*************************************************************/
