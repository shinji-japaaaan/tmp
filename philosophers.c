// 哲学者のルーチン
void *philosopher_routine(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;
    t_table *table = philosopher->table;

    while (1) {
        // フラグ確認
        pthread_mutex_lock(&table->simulation_mutex);
        if (!table->simulation_active) {
            pthread_mutex_unlock(&table->simulation_mutex);
            break;
        }
        pthread_mutex_unlock(&table->simulation_mutex);

        // フォークを取る
        pthread_mutex_lock(philosopher->left_fork);
        pthread_mutex_lock(&table->simulation_mutex);
        if (!table->simulation_active) {
            pthread_mutex_unlock(&table->simulation_mutex);
            pthread_mutex_unlock(philosopher->left_fork);
            break;
        }
        pthread_mutex_unlock(&table->simulation_mutex);
        printf("%ld %d has taken a fork\n", get_current_time(), philosopher->id);

        pthread_mutex_lock(philosopher->right_fork);
        pthread_mutex_lock(&table->simulation_mutex);
        if (!table->simulation_active) {
            pthread_mutex_unlock(&table->simulation_mutex);
            pthread_mutex_unlock(philosopher->left_fork);
            pthread_mutex_unlock(philosopher->right_fork);
            break;
        }
        pthread_mutex_unlock(&table->simulation_mutex);
        printf("%ld %d has taken a fork\n", get_current_time(), philosopher->id);

        // 食事する
        philosopher->last_meal_time = get_current_time();
        philosopher->meals_eaten++;
        printf("%ld %d is eating\n", get_current_time(), philosopher->id);
        usleep(table->time_to_eat * 1000);

        pthread_mutex_unlock(philosopher->right_fork);
        pthread_mutex_unlock(philosopher->left_fork);

        // 休む
        pthread_mutex_lock(&table->simulation_mutex);
        if (!table->simulation_active) {
            pthread_mutex_unlock(&table->simulation_mutex);
            break;
        }
        pthread_mutex_unlock(&table->simulation_mutex);
        printf("%ld %d is sleeping\n", get_current_time(), philosopher->id);
        usleep(table->time_to_sleep * 1000);

        // 考える
        pthread_mutex_lock(&table->simulation_mutex);
        if (!table->simulation_active) {
            pthread_mutex_unlock(&table->simulation_mutex);
            break;
        }
        pthread_mutex_unlock(&table->simulation_mutex);
        printf("%ld %d is thinking\n", get_current_time(), philosopher->id);
    }
    return NULL;
}
