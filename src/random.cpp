#include "random.h"

bool bernouilli(float p)
{
    std::random_device          rd;
    std::mt19937                gen(rd());
    std::bernoulli_distribution d(p);
    return d(gen);
}
