#include "agent.h"
#include "environment.h"
#include <iostream>
#include <unistd.h>

int main()
{
    Environment env(10);
    Agent agent;

    for (int episode = 0; episode < 200; ++episode)
    {
        State state = env.reset();
        int total_reward = 0;

        for (int step = 0; step < 100; ++step)
        {
            int action = agent.select_action(state);
            auto [next_state, reward, done] = env.step(action);

            agent.update(state, action, reward, next_state);
            state = next_state;
            total_reward += reward;

            env.render();
            usleep(100000); // 100ms delay for visualization

            if (done)
                break;
        }

        std::cout << "Episode " << episode + 1 << ": Total reward = " << total_reward << "\n\n";
    }

    return 0;
}
