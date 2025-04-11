#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <tuple>
#include <set>

typedef std::tuple<int, int> State;

class Environment
{
public:
    Environment(int grid_size);
    State reset();
    std::tuple<State, int, bool> step(int action);
    void render();

private:
    int size;
    State agent_pos;
    State goal;
    std::set<State> obstacles;
};

#endif
