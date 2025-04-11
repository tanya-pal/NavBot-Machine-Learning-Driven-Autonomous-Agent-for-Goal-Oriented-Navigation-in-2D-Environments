#include "agent.h"
#include <random>
#include <algorithm>
#include <iostream>

Agent::Agent(double alpha, double gamma, double epsilon)
    : alpha(alpha), gamma(gamma), epsilon(epsilon) {}

std::string Agent::state_key(State state)
{
    return std::to_string(std::get<0>(state)) + "," + std::to_string(std::get<1>(state));
}

int Agent::select_action(State state)
{
    std::string key = state_key(state);
    if (q_table.find(key) == q_table.end())
    {
        q_table[key] = std::vector<double>(4, 0.0); // 4 actions
    }

    if ((double)rand() / RAND_MAX < epsilon)
    {
        return rand() % 4;
    }

    std::vector<double> q_vals = q_table[key];
    return std::distance(q_vals.begin(), std::max_element(q_vals.begin(), q_vals.end()));
}

void Agent::update(State state, int action, int reward, State next_state)
{
    std::string key = state_key(state);
    std::string next_key = state_key(next_state);

    if (q_table.find(key) == q_table.end())
        q_table[key] = std::vector<double>(4, 0.0);

    if (q_table.find(next_key) == q_table.end())
        q_table[next_key] = std::vector<double>(4, 0.0);

    double predict = q_table[key][action];
    double target = reward + gamma * (*std::max_element(q_table[next_key].begin(), q_table[next_key].end()));

    q_table[key][action] += alpha * (target - predict);
}
