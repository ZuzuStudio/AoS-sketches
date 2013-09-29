#ifndef MAP_LOGIC_H
#define MAP_LOGIC_H

enum Territori {Land, Sea};
enum Direction {North, West, East, South};

struct LogicItem
{
    Territori type;
};

class map_logic
{
public:
    map_logic();
    map_logic(int height, int width);
    ~map_logic();

    void resize(int height, int width);
    void generation();
    LogicItem getElement(int row, int column);
    void changeType(Territori type, int row, int column);

private:
    LogicItem **map;
    int width, height;

};

#endif // MAP_LOGIC_H
