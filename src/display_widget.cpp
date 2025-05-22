/**
 * @file: display_widget.cpp
 * 
 * @brief: implementation of the DisplayWidget class
 * 
 * @date:
 * - created on 2025-05-22
 * - updated on 2025-05-22
 **/

#include "display_widget.hpp"

rf::DisplayWidget::DisplayWidget(QWidget* parent)
    : QQuickWidget(parent)
{
    setResizeMode(QQuickWidget::SizeRootObjectToView);
    setSource(QUrl("qrc:/qml/Display.qml"));
}

rf::DisplayWidget::~DisplayWidget() = default;
