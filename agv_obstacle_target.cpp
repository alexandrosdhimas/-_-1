#include<iostream>
using namespace std;

#define N 5

class grid{
    public:
        grid();
        ~grid() {};
        void set_cell(int in_x,int in_y);
        void print_grid();
    private:
        char p[N][N];    
};

{
// class coordinates{
//     public:
//         coordinates();
//         coordinates(int in_x, int in_y);
//         ~coordinates() {};
//         void set_coordinates(int in_x, int in_y);
//         int get_x();
//         int get_y();
//     private:
//         int x;
//         int y;
// };
}

class vehicle{
    public:
        vehicle();
        vehicle(int in_x, int in_y);
        ~vehicle() {};
        int get_x() const;
        int get_y() const;
        void move_up();
        void move_down();
        void move_right();
        void move_left();
        void print_position(grid &ob);
    private:
        int x;
        int y;
};

class obstacle{
    public:
        obstacle();
        ~obstacle() {};
        // void move();
    private:
        int x;
        int y;
};

class target{
    public:
        target();
        ~target() {};
    private:
        int x;
        int y;
};

int main()
{
    grid g;
    g.print_grid();

    vehicle v;
    v.print_position(g);
    v.move_up();
    v.print_position(g);
    v.move_left();
    v.print_position(g);
    v.move_left();
    v.print_position(g);
    v.move_down();
    v.print_position(g);
    v.move_right();
    v.print_position(g);

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

void grid::set_cell(int in_x, int in_y)
{
    int x = in_x;
    int y = in_y;

    p[y-1][x-1] = 'V';
}

{
// coordinates::coordinates()
// {
//     x = 0;
//     y = 0;
// }

// coordinates::coordinates(int in_x, int in_y)
// {
//     x = in_x;
//     y = in_y;
// }

// void coordinates::set_coordinates(int in_x, int in_y)
// {
//     x = in_x;
//     y = in_y;
// }

// int coordinates::get_x()
// {
//     return x;
// }

// int coordinates::get_y()
// {
//     return y;
// }
}

vehicle::vehicle()
{
    x = 4;
    y = 5;
}

vehicle::vehicle(int in_x, int in_y)
{
    x = in_x-1;
    y = in_y-1;
}

void vehicle::move_up()
{
    y--;
}

void vehicle::move_down()
{
    y++;
}

void vehicle::move_right()
{
    x++;
}

void vehicle::move_left()
{
    x--;
}

void vehicle::print_position(grid &ob)
{
    ob.set_cell(x,y);
    ob.print_grid();
}

int vehicle::get_x() const
{
    return x;
}

int vehicle::get_y() const
{
    return y;
}

obstacle::obstacle()
{
    x = 2;
    y = 1;
}

target::target()
{
    x = 1;
    y = 3;
}