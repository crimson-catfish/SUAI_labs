#include <iostream>
#include <cmath>
using namespace std;

// convex quadrilateral
class Quad
{
    private:
        class Vertex
        {
            public: float x, y;
        };

        // verticies of quad
        Vertex vrts[4];

        bool are_opposite_sides_equal()
        {
            return (pow(vrts[0].x - vrts[1].x, 2) + pow(vrts[0].y - vrts[1].y, 2) == pow(vrts[2].x - vrts[3].x, 2) + pow(vrts[2].y - vrts[3].y, 2))
                && (pow(vrts[1].x - vrts[2].x, 2) + pow(vrts[1].y - vrts[2].y, 2) == pow(vrts[3].x - vrts[0].x, 2) + pow(vrts[3].y - vrts[0].y, 2));
        }

    public:
        Quad()
        {
            cout << "Enter X and Y for each vertex of convex quadrilateral:\n";
            for (int i = 0; i < 4; i++)
            {
                cin >> vrts[i].x;
                cin >> vrts[i].y;
            }
        }

        bool is_parallelogram()
        {
            return are_opposite_sides_equal();
        }

        void is_parallelogram(bool * out)
        {
            *out = are_opposite_sides_equal();
        }

        void is_parallelogram(bool & out)
        {
            out = are_opposite_sides_equal();
        }
};

int main()
{
    char quitOrRestart = 'r';

    do
    {
        Quad quad;

        cout << "\nOutput via return:    ";
        if (quad.is_parallelogram()) cout << "This is a parallelogram!";
        else cout << "This is just a quadrilateral";

        bool result;

        cout << "\nOutput via pointer:   ";
        quad.is_parallelogram(&result);
        if (result) cout << "This is a parallelogram!";
        else cout << "This is just a quadrilateral";

        cout << "\nOutput via reference: ";
        quad.is_parallelogram(result);
        if (result) cout << "This is a parallelogram!";
        else cout << "This is just a quadrilateral";

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}

