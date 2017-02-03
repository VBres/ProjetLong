#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>

void viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
{
	viewer.setBackgroundColor (5, 5, 5);
}

//void viewerPsycho (pcl::visualization::PCLVisualizer& viewer)
//{
//	static unsigned count = 0;
//	std::stringstream ss;
//	ss << "Once per viewer loop: " << count++;
//	viewer.removeShape ("text", 0);
//	viewer.addText (ss.str(), 200, 300, "text", 0);
//}

int main (int argc, char *argv[]) {

	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);
	pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
	//viewer.setBackgroundColor (10, 10, 10);
	pcl::io::loadPCDFile (argv[1], *cloud);
	viewer.showCloud (cloud);
	viewer.runOnVisualizationThreadOnce (viewerOneOff);
        //viewer.runOnVisualizationThread (viewerPsycho);

	while (!viewer.wasStopped ())
	{
	}



	return 0;

}
