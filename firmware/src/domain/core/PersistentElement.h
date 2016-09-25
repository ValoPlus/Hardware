#ifndef ESP32_PERSISTENTELEMENT_H
#define ESP32_PERSISTENTELEMENT_H

/**
 *  PersistentElements can be stored with the PersistentService
 */
class PersistentElement {
private:
    int tableRow;
public:
    int getTableRow() { return this->tableRow; }
    void setTableRow(int tableRow) { this->tableRow = tableRow; }
};

#endif //ESP32_PERSISTENTELEMENT_H
