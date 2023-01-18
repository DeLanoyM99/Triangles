#include "pch.h"
#include "CppUnitTest.h"
#include "TriangleMesh.h"
#include "Vertex.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;


namespace Testing
{


	TEST_CLASS(TriangleMeshTest)
	{
	public:

		TEST_METHOD(CreateEmpty)
		{
			auto mesh = make_shared<CTriangleMesh>();
			Assert::AreEqual(0, mesh->GetNumTriangles());
		}

		TEST_METHOD(OneTriangle)
		{
			auto mesh = make_shared<CTriangleMesh>();
			auto v1 = mesh->AddVertex(10, 12);
			auto v2 = mesh->AddVertex(20, 24);
			auto v3 = mesh->AddVertex(15, 89);
			auto color = Color(12, 34, 56);

			Assert::AreEqual(10, v1->GetX());
			Assert::AreEqual(12, v1->GetY());

			auto t1 = mesh->AddTriangle(v1, v2, v3, color);

			Assert::AreEqual(1, mesh->GetNumTriangles());
			Assert::IsTrue(t1 == mesh->GetTriangle(0));

			t1 = mesh->GetTriangle(0);
			Assert::AreEqual(color.ToCOLORREF(), t1->GetColor().ToCOLORREF());
			Assert::IsTrue(v1 == t1->GetV1());
			Assert::IsTrue(v2 == t1->GetV2());
			Assert::IsTrue(v3 == t1->GetV3());
		}


	};
}
