#include "ballpivot.h"
#include "ui_ballpivot.h"
using namespace vcg;
using namespace std;

class MyFace;
class MyVertex;

struct MyUsedTypes : public UsedTypes<	Use<MyVertex>		::AsVertexType,
                                                                                Use<MyFace>			::AsFaceType>{};

class MyVertex  : public Vertex< MyUsedTypes, vertex::Coord3f, vertex::Normal3f, vertex::BitFlags, vertex::Mark>{};
class MyFace    : public Face  < MyUsedTypes, face::VertexRef, face::Normal3f, face::BitFlags > {};
class MyMesh    : public vcg::tri::TriMesh< vector<MyVertex>, vector<MyFace> > {};

ballpivot::ballpivot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ballpivot)
{
    ui->setupUi(this);
}

ballpivot::~ballpivot()
{
    delete ui;
}

void ballpivot::on_buttonBox_accepted()
{
    angle = ui->angle->value();
    radius = ui->radius->value();
    cluster = ui->cluster->value();
}

void ballpivot::setFile(string fileName)
{
    file = fileName;
    qDebug() << "Set file name sucess";

}

void ballpivot::buildMesh(){
    const char *fileName = file.c_str();
    CMeshO m;
    m.vert.EnableMark();

    m.vert.EnableVFAdjacency();
    m.face.EnableVFAdjacency();
    tri::UpdateTopology<CMeshO>::VertexFace(m);

  //  m.updateDataMask(MeshModel::MM_VERTFACETOPO);

    if(vcg::tri::io::ImporterXYZ<CMeshO>::Open(m,fileName, 0))
    {
        qDebug() << "Load file fail";
    }
 // vcg::tri::UpdateBounding<MyMesh>::Box(m);
 // vcg::tri::UpdateNormal<MyMesh>::PerFace(m);
 // printf("Input mesh  vn:%i fn:%i\n",m.VN(),m.FN());

  // Initialization
  tri::BallPivoting<CMeshO> pivot(m, radius,cluster/100, angle*M_PI/180);
  // the main processing
  qDebug() << "Pivot file sucess";
  pivot.BuildMesh(0);
  qDebug() << "Build mesh file sucess";

   m.face.DisableFFAdjacency();

  //printf("Output mesh vn:%i fn:%i\n",m.VN(),m.FN());
//  printf("Created in :%i msec (%i+%i)\n",t2-t0,t1-t0,t2-t1);

    vcg::tri::io::ExporterPLY<CMeshO>::Save(m,"result.ply",false);
}
