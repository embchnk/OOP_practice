#ifndef DO_UNDO_H
#define DO_UNDO_H

class Msg;

class DoUndoAction {
public:
	DoUndoAction(int& acc)
		: _backup (acc) 
	{}
	DoUndoAction()
		: _backup (0)
	{}
	virtual ~DoUndoAction() {}
	virtual void dodo() {}
	virtual void undoOk() {}
	virtual void undoFail() {}
	virtual void backupFoo() {}
protected:
	int _backup;
};

class KeepInt: public DoUndoAction {
public:
	KeepInt(int& acc)
		: DoUndoAction(acc)
		, _account (&acc)
	{}
	void backupFoo() {
		*_account = _backup;
	}
private:
	int* _account;
};

class DoUndo {
public:
	DoUndo() {}
	DoUndo(DoUndoAction* msg)
		: _ptr (msg) 
	{
		_ptr -> dodo();
		_flag = 0;
	}
	DoUndo(KeepInt* keepint)
		: _ptr (keepint) 
	{}
	~DoUndo() {
		if (_flag) {
			_ptr -> undoOk();
			delete _ptr;
		}
		else {
			_ptr -> backupFoo();
			_ptr -> undoFail();
		}
	}
	static void allok() {
		_flag = 1;
	}
	static bool _flag;
private:
	DoUndoAction* _ptr;

};

bool DoUndo::_flag = 0;

#endif // DO_UNDO_H
