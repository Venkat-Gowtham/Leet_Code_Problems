class Solution {
public:
    // Custom comparator to sort enemies by damage per second in descending order.
    // If damage per second is the same, sort by health in descending order.
    static bool comp(const pair<int, pair<int, double>>& a, const pair<int, pair<int, double>>& b) {
        if (a.second.second == b.second.second) {
            return a.second.first > b.second.first;
        }
        return a.second.second > b.second.second;
    }

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int, pair<int, double>>> enemies; // Vector to store damage, health, and damage per second.
        long long totalDamage = 0; // Sum of all damage values.
        int n = damage.size(); // Number of enemies.
        
        // Calculate the damage per second for each enemy and store it along with damage and health.
        for (int i = 0; i < n; i++) {
            long long sec = health[i] / power; // Calculate how many seconds are needed to defeat this enemy.
            if (health[i] % power) sec++; // If there's a remainder, add an extra second.
            enemies.push_back({damage[i], {health[i], (double)damage[i] / sec}}); // Store damage, health, and damage per second.
            totalDamage += damage[i]; // Accumulate the total damage.
        }

        // Sort enemies based on the custom comparator.
        sort(enemies.begin(), enemies.end(), comp);

        long long result = 0; // Initialize result for the minimum total damage.

        // Calculate the total damage required to defeat all enemies.
        for (int i = 0; i < n; i++) {
            long long damageValue = enemies[i].first; // Current enemy's damage.
            long long healthValue = enemies[i].second.first; // Current enemy's health.
            long long sec = healthValue / power; // Calculate how many seconds are needed to defeat this enemy.
            if (healthValue % power) sec++; // If there's a remainder, add an extra second.
            result += sec * totalDamage; // Add the damage contribution of this enemy.
            totalDamage -= damageValue; // Subtract the current enemy's damage from the total remaining damage.
        }

        return result; // Return the minimum total damage required.
    }
};