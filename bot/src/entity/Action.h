#ifndef ACTION
#define ACTION

#include "yaml-cpp/node/node.h"

enum class Order { IGNORE, BUY, SELL };

struct OrderData {
    explicit OrderData(Order action, float quantity)
        : action(action), quantity(quantity) {}
    Order action;
    float quantity;
};

namespace YAML {
template <>
struct convert<Order> {
    static Node encode(const Order &rhs) {
        Node node;
        node.push_back((int)rhs);
        return node;
    }

    static bool decode(const Node &node, Order &rhs) {
        rhs = static_cast<Order>(node.as<int>());
        return true;
    }
};

template <>
struct convert<OrderData> {
    static Node encode(const OrderData &rhs) {
        Node node;
        node["action"].push_back(rhs.action);
        node["quantity"].push_back(rhs.quantity);
        return node;
    }

    static bool decode(const Node &node, OrderData &rhs) {
        rhs.action = node["action"].as<Order>();
        rhs.quantity = node["quantity"].as<float>();
        return true;
    }
};
}  // namespace YAML
#endif
