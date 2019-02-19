#ifndef BALLPIVOT_H
#define BALLPIVOT_H

#include <QDialog>
#include<vcg/complex/complex.h>

#include <vcg/complex/algorithms/update/bounding.h>
#include <vcg/complex/algorithms/update/topology.h>
#include <vcg/complex/algorithms/update/normal.h>
#include <vcg/complex/algorithms/update/flag.h>
#include <vcg/complex/algorithms/create/ball_pivoting.h>
#include <vcg/container/container_allocation_table.h>
#include <QDebug>
// input output
#include <wrap/io_trimesh/import_ply.h>
#include <wrap/io_trimesh/export_ply.h>
#include <importxyz.h>
#include <mesh_type.h>
namespace Ui {
class ballpivot;
}

class ballpivot : public QDialog
{
    Q_OBJECT

public:
    explicit ballpivot(QWidget *parent = 0);
    double angle;
    double radius;
    double cluster;
    ~ballpivot();
    void buildMesh();
    void setFile(string fileName);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ballpivot *ui;
    const double halfC = 3.14/180;
    string file;
};

#endif // BALLPIVOT_H
