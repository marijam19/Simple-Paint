#include <iostream>
#include <QDebug>
#include "headers/colorpicker.h"

ColorPicker::ColorPicker(QColor* primary, QColor* secondary, QImage* img)
    : Tool::Tool(img), myPrimary(primary), mySecondary(secondary) {}

ColorPicker::~ColorPicker() = default;

/* mouse events */
void ColorPicker::mouseClicked(QMouseEvent* event) {
  event->ignore();
}

void ColorPicker::mouseMoved(QMouseEvent* event) {
  event->ignore();
}

void ColorPicker::mouseReleased(QMouseEvent* event) {
  pickerButton = event->button();
  paint(event->pos());
}

void ColorPicker::setWidth(const int width) {
  Q_UNUSED(width)
}

/* colorpicker's logic */
void ColorPicker::paint(QPoint endPoint) {
  QPainter painter(image);

  auto Color = image->pixelColor(endPoint);
  if(pickerButton == Qt::LeftButton)
    *myPrimary = Color;
  else
    *mySecondary = Color;
}
