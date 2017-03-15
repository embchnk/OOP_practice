#ifndef NODE_H
#define NODE_H

class node
{
public:
	node();
	node( int );
	~node();
	node* retPtr(){ return _next; }
	int retVal(){ return _value; }
	void addPointer( node* );
private:
	node* _next;
	int _value;	
};


#endif // NODE_H
