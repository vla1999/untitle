#pragma once

#include <stddef.h>
#include <stdlib.h>

#include <aerospike/aerospike.h>
#include <aerospike/aerospike_key.h>
#include <aerospike/as_error.h>
#include <aerospike/as_record.h>
#include <aerospike/as_status.h>
#include "example_utils.h"

//#include <opencv2/core.hpp>
//#include <opencv2/hdf.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;

int main2(){
	//String dataset_name = "/barcodes_int";
	//cv::Ptr<cv::hdf::HDF5> h5io = cv::hdf::open("c:\\Users\\vla19\\Downloads\\barcode_NN.hdf5");
	//Mat data;
	//h5io->dsread(data, dataset_name);
	//for (int i = 0; i < 10; i++)
	//	//for (int j = 0; j < data.cols; j++)
	//	cout << data.row(i) << "\n";
	//h5io->close();
	//main4();

	as_error err;
	as_record rec;
	aerospike as;
	example_connect_to_aerospike(&as);
	strcpy(g_set, "set2");
	strcpy(g_key_str, "key2");


	char *bin_names[10];


	for(int i = 0; i < 10; i++)
	{
		bin_names[i] = (char*)malloc(sizeof(char) * 4);
		snprintf(bin_names[i],2,"%d",i);
	}

	// write 1000 records then read 1000 records
	for (int j = 1; j <= 1000; j++)
	{  
		snprintf(g_key_str, 2, "%d", j);
		as_key_init_str(&g_key, g_namespace, g_set, g_key_str);
		as_record_init(&rec, 100);
	/*	for (int i = 0; i < 100; j++)
		{
			as_record_set_int64(&rec, bin_names[i], rand());
		}
		if (aerospike_key_put(&as, &err, NULL, &g_key, &rec) !=
			AEROSPIKE_ERR_RECORD_EXISTS) {
			LOG("aerospike_key_put() error", err.code, err.message);
			exit(-1);
		}*/
	}
	example_cleanup(&as);
	for (int i = 0; i < 10; i++)
	{
		free(bin_names[i]);
	}
	return 0;
}
