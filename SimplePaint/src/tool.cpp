#include "headers/tool.h"

Tool::Tool(QColor* color, const int width, QImage* img)
    : myColor(color), myWidth(width), image(img) {}

Tool::Tool(QColor* color, QImage* img) : myColor(color), image(img) {}

Tool::Tool(QImage* img) : myColor(nullptr), myWidth(0), image(img) {}

Tool::~Tool() = default;
