#include<iostream>
using namespace std;

#define N 6

class grid{
    public:
        grid();
        ~grid() {};
        friend class vehicle;
        friend class obstacle;
        friend class target;
        void print_grid();
    private:
        char p[N][N];    
};

class coordinates{
    public:
        coordinates();
        coordinates(int in_x, int in_y);
        ~coordinates() {};
        void set_coordinates(int in_x, int in_y);
        int get_x();
        int get_y();
    private:
        int x;
        int y;
};

class vehicle{
    public:
        vehicle();
        vehicle(coordinates in_position);
        ~vehicle() {};
        void move_up();
        void move_down();
        void move_right();
        void move_left();
        void print_position(grid &ob);
    private:
        coordinates position;
};

class obstacle{
    public:
        obstacle();
        ~obstacle() {};
        // void move();
    private:
        coordinates position;
};

class target{
    public:
        target();
        ~target() {};
    private:
        coordinates position;
};

int main()
{
    grid g;
    g.print_grid();

    vehicle v;
    v.print_position(g);
    g.print_grid();
    v.move_left();
    v.print_position(g);
    g.print_grid();

    return 0;
}

grid::grid()
{
    int i,j;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            p[i][j] = '*';
}

void grid::print_grid()
{
    cout<<endl;

    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
            cout<<p[i][j];
        cout<<endl;
    }
    cout<<endl;
}

coordinates::coordinates()
{
    x = 0;
    y = 0;
}

coordinates::coordinates(int in_x, int in_y)
{
    x = in_x;
    y = in_y;
}

void coordinates::set_coordinates(int in_x, int in_y)
{
    x = in_x;
    y = in_y;
}

int coordinates::get_x()
{
    return x;
}

int coordinates::get_y()
{
    return y;
}

vehicle::vehicle()
{
    coordinates vehicle_initial_position(4,3);
    position = vehicle_initial_position;
}

vehicle::vehicle(coordinates in_position)
{
    position = in_position;
}

void vehicle::move_up()
{
    int x = position.get_x();
    int y = position.get_y();
    position.set_coordinates(x, y-1);
}
void vehicle::move_down()
{
    int x = position.get_x();
    int y = position.get_y();
    position.set_coordinates(x, y+1);
}
void vehicle::move_right()
{
    int x = position.get_x();
    int y = position.get_y();
    position.set_coordinates(x+1, y);
}
void vehicle::move_left()
{
    int x = position.get_x();
    int y = position.get_y();
    position.set_coordinates(x-1, y);
}
void vehicle::print_position(grid &ob)
{
    ob.p[position.get_x()][position.get_y()] = 'V';
}

obstacle::obstacle()
{
    coordinates obstacle_initial_position(2,1);
    position = obstacle_initial_position;
}

target::target()
{
    coordinates target_initial_position(2,1);
    position = target_initial_position;
}