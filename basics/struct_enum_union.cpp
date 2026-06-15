//struct: Good for grouping data but lacks encapsulation in C
//enum : Good for symbolic constants limited to integers
//union : saves memory , but only one member is valid at a give time (memory is allocated for max of all the members )
#include<string>
#include<iostream>
using namespace std;

struct Token {
	enum Tokentype {Identifier ,  Number , Keyword , Operator } type;
	//type is a variable that can store one of the values defined in tokentype
	//enum name Tokentype , enum type ->type 
	string lexeme;
	int line;
};
void printToken(const Token &t) {
	std::cout<< "Token:"<<t.lexeme<< "(line "<< t.line << ") type:"<<endl;
	switch(t.type){
		case Token::Identifier : cout <<"Identifier"<<endl;
		break;
		case Token::Number : cout<<"Number"<<endl;
	        break;
		case Token::Keyword : cout<<"Keyword"<<endl;
	        break;
	        case Token::Operator : cout<<"operator"<<endl;
	        break;
		default :
	        cout<<"Invalid"<<endl;
	}
}
struct Symbol {
	enum{ INT,FLOAT,STRING} type;
	union {
		int iVal;
		float fVal;
		char* sVal;
	} value;
};

int main()
{
	Symbol s;
	s.type = Symbol::INT;
	cout<<"s.type: "<<s.type<<endl;
	s.value.iVal=42;
	
	return 0;
}


