#ifndef AGENT_H
#define AGENT_H

#include <unordered_map>
#include <vector>
#include <tuple>

typedef std::tuple<int, int> State;

class Agent
{
public:
    Agent(double alpha = 0.1, double gamma = 0.9, double epsilon = 0.1);
    int select_action(State state);
    void update(State state, int action, int reward, State next_state);

private:
    std::unordered_map<std::string, std::vector<double>> q_table;
    double alpha, gamma, epsilon;
    std::string state_key(State state);
};

#endif
