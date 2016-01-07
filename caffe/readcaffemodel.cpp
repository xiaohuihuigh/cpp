
#include <stdio.h>
   #include <string.h>
   #include <fstream>
   #include <iostream>
   #include "proto/caffe.pb.h"

  using namespace std;
   using namespace caffe;

  int main(int argc, char* argv[])
  {
   caffe::NetParameter msg;
   fstream input("lenet_iter_10000.caffemodel", ios::in | ios::binary);
      if (!msg.ParseFromIstream(&input))
  {
     cerr << "Failed to parse address book." << endl;
     return -1;
   }
   printf("length = %d\n", length);
   printf("Repeated Size = %d\n", msg.layer_size());

   ::google::protobuf::RepeatedPtrField< LayerParameter >* layer = msg.mutable_layer();
   ::google::protobuf::RepeatedPtrField< LayerParameter >::iterator it = layer->begin();
   for (; it != layer->end(); ++it)
   {
     cout << it->name() << endl;
     cout << it->type() << endl;
     cout << it->convolution_param().weight_filler().max() << endl;
   }

   return 0;
  }
