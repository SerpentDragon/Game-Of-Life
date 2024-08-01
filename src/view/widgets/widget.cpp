#include "widget.h"

Widget::Widget(SDL_Renderer* renderer, int x, int y, int width, int height)
    : renderer_(renderer), x_(x), y_(y), width_(width), height_(height),
    widget_rect_({ x, y, width, height })
{

}

bool Widget::inside_widget(int x, int y) const
{
    return x_ <= x && x <= x_ + width_ && y_ <= y && y <= y_ + height_;
}