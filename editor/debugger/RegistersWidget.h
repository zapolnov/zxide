#ifndef DEBUGGER_REGISTERSWIDGET_H
#define DEBUGGER_REGISTERSWIDGET_H

#include <QOpenGLWidget>
#include "debugger/EmulatorCore.h"
#include "util/SimpleTextPainter.h"
#include <memory>
#include <vector>
#include <string>

class QTimer;

class RegistersWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit RegistersWidget(QWidget* parent = nullptr);
    ~RegistersWidget() override;

    void refresh();
    void reset();

    void setOrientation(Qt::Orientation orientation);

protected:
    void paintGL() override;
    void contextMenuEvent(QContextMenuEvent* event) override;

private:
    enum Mode
    {
        Decimal_Unsigned = 0,
        Decimal_Signed,
        Hexadecimal_Unsigned,
        Hexadecimal_Signed,
    };

    class AbstractRegister : public SimpleTextPainter
    {
    public:
        AbstractRegister();
        virtual ~AbstractRegister();

        virtual int x() const = 0;
        virtual int y() const = 0;
        virtual int width() const = 0;

        virtual bool isValid() const = 0;
        virtual void clear() = 0;
        virtual void updateValue(const Registers& reg) = 0;

        virtual void paint(QPainter* painter) const = 0;

        virtual void showContextMenu(const QPoint& pos) = 0;
    };

    template <typename T> class Register : public AbstractRegister
    {
    public:
        Register(RegistersWidget* widget, ::Register reg,
            int hx, int hy, int vx, int vy, int nw, int nw2, ptrdiff_t offset, std::string name);

        int x() const final override;
        int y() const final override;
        int nameWidth() const;
        int width() const override;

        Mode mode() const { return mMode; }
        void setMode(Mode mode);

        bool isValid() const final override { return mIsValid; }
        void clear() final override;
        void updateValue(const Registers& reg) final override;

        void paint(QPainter* painter) const override;

        void showContextMenu(const QPoint& pos) override;

    protected:
        RegistersWidget* const mWidget;
        const ::Register mRegister;
        const int mHorizontalX;
        const int mHorizontalY;
        const int mVerticalX;
        const int mVerticalY;
        const std::string mName;
        const ptrdiff_t mOffset;
        const int mNameWidth;
        const int mNameWidthHorz;
        Mode mMode;
        T mValue;
        T mOldValue;
        bool mIsValid;
    };

    class SimpleRegister final : public Register<quint8>
    {
    public:
        SimpleRegister(RegistersWidget* w, int hx, int hy, int vx, int vy, int nw, int nw2, ptrdiff_t o, std::string n);
        int width() const final override;
        void paint(QPainter* painter) const final override;
        void showContextMenu(const QPoint& pos) final override;
    };

    class Flag final : public Register<bool>
    {
    public:
        Flag(RegistersWidget* widget, int hx, int hy, int vx, int vy, int nw, ptrdiff_t offset, std::string name);
        int width() const final override;
        void paint(QPainter* painter) const final override;
        void showContextMenu(const QPoint& pos) final override;
    };

    class TStates final : public Register<quint8>
    {
    public:
        TStates(RegistersWidget* widget, int hx, int hy, int vx, int vy, int nw, ptrdiff_t offset, std::string name);
        int width() const final override;
        void paint(QPainter* painter) const final override;
        void showContextMenu(const QPoint& pos) final override;
    };

    class ULA final : public Register<quint8>
    {
    public:
        ULA(RegistersWidget* widget, int hx, int hy, int vx, int vy, int nw, ptrdiff_t offset, std::string name);
        void showContextMenu(const QPoint& pos) final override;
    };

    std::vector<std::unique_ptr<AbstractRegister>> mRegisters;
    Qt::Orientation mOrientation;
    QTimer* mTimer;

    Q_DISABLE_COPY(RegistersWidget)
};

#endif
