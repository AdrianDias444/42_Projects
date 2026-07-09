// Possible data race

int counter = 0;

void increment_counter(void)
{
    counter = counter + 1;
}

void reader(void)
{
    int val = counter;
}

int main(void)
{

}