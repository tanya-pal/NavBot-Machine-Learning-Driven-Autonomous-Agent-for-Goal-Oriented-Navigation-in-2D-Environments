# NavBot: Q-Learning Autonomous Agent for Goal-Oriented Navigation in a 2D Grid World

An autonomous agent that learns, through trial and error, how to travel from a start cell to a goal cell on a 2D grid while avoiding obstacles. There are no hard-coded paths or rules: the agent uses **tabular Q-learning** (reinforcement learning) and discovers the route purely from rewards.

The project is implemented twice, in **Python** (with a live Pygame visualization) and in **C++** (a terminal version), so the same algorithm can be compared across both languages.

<!-- TODO: add your own demo GIF or screenshot here, e.g. ![NavBot demo](demo.gif) -->

## Features

- 10 x 10 grid world with a fixed start (top-left), goal (bottom-right) and obstacles
- Q-learning agent with epsilon-greedy exploration (no hard-coded rules)
- Reward design: **+100** for reaching the goal, **-1** for every move
- Moves into walls or obstacles are ignored (the agent stays in place)
- Python version: real-time Pygame visualization with per-episode logging of steps and reward
- C++ version: ASCII grid rendering in the terminal (`A` agent, `G` goal, `X` obstacle)

## How It Works

| Component | Details |
|---|---|
| **State** | The agent's `(x, y)` grid position |
| **Actions** | 0: x-1 (left), 1: x+1 (right), 2: y-1 (up), 3: y+1 (down) |
| **Reward** | +100 on reaching the goal, -1 per step |
| **Update rule** | `Q(s,a) <- Q(s,a) + alpha * (r + gamma * max Q(s',a') - Q(s,a))` |
| **Hyperparameters** | alpha = 0.1, gamma = 0.9, epsilon = 0.1 |
| **Training** | 200 episodes |
| **Q-table** | Dictionary keyed by state, created lazily as new states are visited |

**Obstacle layouts**
- Python: `(3,3) (3,4) (4,3) (6,6) (7,6) (8,6)`
- C++: `(3,3) (4,4) (5,5) (6,6)` (a diagonal wall)

## Results

Measured over 10 random seeds, 200 training episodes each, on the Python environment (shortest possible path = 18 steps):

| Metric | Value |
|---|---|
| Steps in episode 1 (no knowledge yet) | about 690 on average |
| Steps in the first 20 episodes | about 240 on average |
| Steps in the last 20 episodes | about 25 on average (near the 18-step optimum, includes 10% random exploration) |

<!-- TODO: re-run the training yourself and update these numbers with your own runs before sharing. -->

## Tech Stack

| Tech | Purpose |
|---|---|
| Python 3 | Environment, Q-learning agent, training loop |
| NumPy | Greedy action selection (`argmax`) |
| Pygame | Real-time visualization of the grid and agent |
| C++ (STL) | Standalone terminal implementation of the same agent and environment |

## Project Structure

```
NavBot/
├── python/
│   ├── main.py          # Training loop + Pygame visualization
│   ├── environment.py   # Grid, obstacles, rewards, drawing
│   ├── agent.py         # Agent wrapper around the Q-learner
│   └── qlearning.py     # Tabular Q-learning implementation
├── cpp/
│   ├── main.cpp         # Training loop + ASCII rendering
│   ├── environment.h / environment.cpp
│   ├── agent.h / agent.cpp
│   └── Makefile
└── README.md
```

## Installation and Usage

```bash
git clone https://github.com/tanya-pal/NavBot-Machine-Learning-Driven-Autonomous-Agent-for-Goal-Oriented-Navigation-in-2D-Environments
cd NavBot-Machine-Learning-Driven-Autonomous-Agent-for-Goal-Oriented-Navigation-in-2D-Environments
```

**Python version**
```bash
pip install pygame numpy
cd python
python main.py
```

**C++ version**
```bash
cd cpp
make
./autonomous_agent
```

## Limitations and Future Work

- With only 200 episodes and a constant epsilon, the learned greedy policy is not always complete. Adding **epsilon decay** and more episodes would make it reliable.
- The state is the exact grid position, so the Q-table does not scale to large or continuous spaces. A **Deep Q-Network (DQN)** would address this.
- Extend to **dynamic obstacles**, random start/goal positions, and partial observability (sensor-based or camera-based navigation).
- Compare the learned policy against classical planners such as **A\*** and **Dijkstra**.
- Visualize the Q-table and the learned policy as a heatmap.

## Author

**Tanya Pal**: B.Tech CSE (Data Science)
[GitHub](https://github.com/tanya-pal) | [LinkedIn](https://www.linkedin.com/in/tanya-pal/)

<!-- TODO (important): if this project is based on or adapted from someone else's code, add an "Acknowledgements" section here crediting the original author and repo. -->
