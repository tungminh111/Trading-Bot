#ifndef ACTION
#define ACTION

enum class Action {
	IGNORE,
	BUY,
	SELL
};

struct ActionData {
	explicit ActionData(Action action, float quantity): action(action), quantity(quantity) {}
	Action action;
	float quantity;
};

#endif
