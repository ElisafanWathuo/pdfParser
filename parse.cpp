#include <podofo/podofo.h>
using namespace PoDoFo;

int main(int argc, char** argv)
{
	std::cout<<"Testing..."<<std::endl;
	PdfMemDocument doc;
	std::cout<<"argv = "<<argv[1]<<std::endl;
	try{
		doc.Load(argv[1]);
		PdfVecObjects objects = doc.GetObjects();
		int pageCount = (objects.GetParentDocument())->GetPageCount();
		for(int i = 0; i < pageCount; i++)
		{
			PdfPage* page = (objects.GetParentDocument())->GetPage(i);
			int annotCount = (int)page->GetNumAnnots();
			for(int j = 0; j < annotCount; j++)
			{
				PdfAnnotation* annot = page->GetAnnotation(j);
				if((annot->GetContents()).GetString() != NULL){
					std::cout<<page->GetAnnotation(j)->GetContents().GetString()<<std::endl;
				}
			}
		}
	}catch(PdfError &error)
	{
		std::cout<<PoDoFo::PdfError::ErrorMessage(error.GetError())<<std::endl;
	}
}
