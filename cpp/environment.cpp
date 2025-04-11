#include "environment.h"
#include <iostream>
#include <cstdlib>

Environment::Environment(int grid_size)
{
    size = grid_size;
    goal = {size - 1, size - 1};
    obstacles = {{3, 3}, {4, 4}, {5, 5}, {6, 6}};
}

State Environment::reset()
{
    agent_pos = {0, 0};
    return agent_pos;
}

std::tuple<State, int, bool> Environment::step(int action)
{
    int x = std::get<0>(agent_pos);
    int y = std::get<1>(agent_pos);

    if (action == 0)
        x--;
    if (action == 1)
        x++;
    if (action == 2)
        y--;
    if (action == 3)
        y++;

    if (x >= 0 && x < size && y >= 0 && y < size && obstacles.find({x, y}) == obstacles.end())
    {
        agent_pos = {x, y};
    }

    bool done = (agent_pos == goal);
    int reward = done ? 100 : -1;

    return {agent_pos, reward, done};
}

void Environment::render()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (agent_pos == std::make_tuple(i, j))
                std::cout << "A ";
            else if (goal == std::make_tuple(i, j))
                std::cout << "G ";
            else if (obstacles.find({i, j}) != obstacles.end())
                std::cout << "X ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
