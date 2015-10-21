#ifndef QXTITEMDELEGATE_H
/****************************************************************************
** Copyright (c) 2006 - 2011, the LibQxt project.
** See the Qxt AUTHORS file for a list of authors and copyright holders.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the LibQxt project nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
** <http://libqxt.org>  <foundation@libqxt.org>
*****************************************************************************/

#define QXTITEMDELEGATE_H

#include <QItemDelegate>
#include "qxtglobal.h"
#include "qxtnamespace.h"

class QxtItemDelegatePrivate;

class QXT_GUI_EXPORT QxtItemDelegate : public QItemDelegate
{
    Q_OBJECT
    QXT_DECLARE_PRIVATE(QxtItemDelegate)
    Q_PROPERTY(Qxt::DecorationStyle decorationStyle READ decorationStyle WRITE setDecorationStyle)
    Q_PROPERTY(Qt::TextElideMode elideMode READ elideMode WRITE setElideMode)
    Q_PROPERTY(QString progressTextFormat READ progressTextFormat WRITE setProgressTextFormat)
    Q_PROPERTY(bool progressTextVisible READ isProgressTextVisible WRITE setProgressTextVisible)

public:
    explicit QxtItemDelegate(QObject* parent = 0);
    virtual ~QxtItemDelegate();

    enum Role
    {
        ProgressValueRole = Qt::UserRole + 328,
        ProgressMinimumRole,
        ProgressMaximumRole
    };

    Qxt::DecorationStyle decorationStyle() const;
    void setDecorationStyle(Qxt::DecorationStyle style);

    Qt::TextElideMode elideMode() const;
    void setElideMode(Qt::TextElideMode mode);

    QString progressTextFormat() const;
    void setProgressTextFormat(const QString& format);

    bool isProgressTextVisible() const;
    void setProgressTextVisible(bool visible);

    virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    virtual void drawDisplay(QPainter* painter, const QStyleOptionViewItem& option, const QRect& rect, const QString& text) const;
    virtual QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

Q_SIGNALS:
    void editingStarted(const QModelIndex& index);
    void editingFinished(const QModelIndex& index);
};

#endif // QXTITEMDELEGATE_H
