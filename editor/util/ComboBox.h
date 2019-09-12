#ifndef UTIL_COMBOBOX_H
#define UTIL_COMBOBOX_H

class QComboBox;
class QVariant;

bool comboSelectItem(QComboBox* combo, const QVariant& value);
QVariant comboSelectedItem(const QComboBox* combo);

#endif
