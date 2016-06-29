// includes for openCV functionality in the item handlers
//#include "opencv2/features2d/features2d.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/core/core.hpp"
#include <iostream>

//#include <process.h>
//#include <boost/date_time.hpp>
#pragma once
namespace Project1 {
	using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		Stream^ myStream;
		Bitmap^ bmp;
		double minalpha;
		double maxalpha;
		double minbeta;
		double maxbeta;
		double brightnessLevel;
		double beta;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^  trackBar1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 2;
			this->trackBar1->Location = System::Drawing::Point(503, 414);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(179, 90);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->Value = 127;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(314, 411);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Load Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(1, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(504, 463);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Location = System::Drawing::Point(503, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(489, 463);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 2;
			this->trackBar2->Location = System::Drawing::Point(805, 415);
			this->trackBar2->Maximum = 255;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(179, 90);
			this->trackBar2->TabIndex = 4;
			this->trackBar2->Value = 127;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(198, 416);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Original Image";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(709, 416);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Result Image";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(565, 446);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Brightness";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(873, 446);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 25);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Contrast";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(412, 411);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Save Image";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(976, 439);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->trackBar1);
			this->ImeMode = System::Windows::Forms::ImeMode::On;
			this->MaximumSize = System::Drawing::Size(1002, 510);
			this->MinimumSize = System::Drawing::Size(1002, 510);
			this->Name = L"MyForm";
			this->Text = L"Image Processing";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:  Bitmap^ ContrastBrightness(Bitmap^ sourceBitmap, double brightnessLevel, double beta)
		{
			// Lock the bitmap's bits.  
			Rectangle rect = Rectangle(0, 0, sourceBitmap->Width, sourceBitmap->Height);
			System::Drawing::Imaging::BitmapData^ sourceData = sourceBitmap->LockBits(rect,System::Drawing::Imaging::ImageLockMode::ReadWrite, sourceBitmap->PixelFormat);

			// Get the address of the first line.
			IntPtr ptr = sourceData->Scan0;
			// Declare an array to hold the bytes of the bitmap.
			// This code is specific to a bitmap with 24 bits per pixels.
			int bytes = Math::Abs(sourceData->Stride) * sourceData->Height;
			array<Byte>^rgbValues = gcnew array<Byte>(bytes);



			System::Runtime::InteropServices::Marshal::Copy(ptr, rgbValues, 0, bytes);


			sourceBitmap->UnlockBits(sourceData); // to use the bitmap, in fact to in order to operate on it


			//double brightnessLevel = Math::Pow((100.0 + threshold) / 100.0, 2);

			double min[] = { rgbValues[0],rgbValues[1],rgbValues[2],rgbValues[3] };
			double max[] = { rgbValues[0],rgbValues[1],rgbValues[2],rgbValues[3] };
			double mid[] = {0,0,0,0};
			double blue = 0;
			double green = 0;
			double red = 0;
			double alpha = 0;
			double bt;
			double tempRGB[4];
			double contrast[] = { 0,0,0,0};
			int tolerance = 5; // +((sourceBitmap->Width + sourceBitmap->Height) - (1600 + 900)) / (sourceBitmap->Width + sourceBitmap->Height);
			int region = tolerance;  // this metric determines the quality of processing and duration because i have not used any thread
			int start = 0;
			
	
			// all the image rgb calculations
			for (int k = 0; k + 4 < rgbValues->Length; k += 4)
			{
				start = 0;
				region = tolerance; 
				if (k >= region)
					start = Math::Abs(k - region);
				if (k + 3 + region > rgbValues->Length)
					region = 0;
				else
					region = tolerance;
				for (int i = start; i + 4 < k + region; i += 4) {

					if (min[0] > rgbValues[i])   min[0] = rgbValues[i];
					if (min[1] > rgbValues[i + 1])   min[1] = rgbValues[i + 1];
					if (min[2] > rgbValues[i + 2])   min[2] = rgbValues[i + 2];
					if (min[3] > rgbValues[i + 3])   min[3] = rgbValues[i + 3];

					if (max[0] < rgbValues[i])   max[0] = rgbValues[i];
					if (max[1] < rgbValues[i + 1])   max[1] = rgbValues[i + 1];
					if (max[2] < rgbValues[i + 2])   max[2] = rgbValues[i + 2];
					if (max[3] < rgbValues[i + 3])   max[3] = rgbValues[i + 3];
				}

				mid[0] = (max[0] + min[0]) / 2;
				mid[1] = (max[1] + min[1]) / 2;
				mid[2] = (max[2] + min[2]) / 2;
				mid[3] = (max[3] + min[3]) / 2;

				contrast[0] = max[0] - min[0];
				contrast[1] = max[1] - min[1];
				contrast[2] = max[2] - min[2];
				contrast[3] = max[3] - min[3];

				bt = (this->maxbeta - this->minbeta) / 2;
				//blue = ((((rgbValues[k] / 255.0) - 0.5) *
					//brightnessLevel) + 0.5) * 255.0;
				if (rgbValues[k] < mid[0]  && beta > 0) {
					tempRGB[0] = 255 - rgbValues[k];
					contrast[0] = -(rgbValues[k] - min[0]);
				}
				else if (rgbValues[k] > mid[0] && beta > 0){
				    tempRGB[0] = rgbValues[k];
					contrast[0] = max[0] - rgbValues[k];
			    }
				else if (rgbValues[k] < mid[0] && beta < 0) {
					tempRGB[0] = 255 - rgbValues[k];
					contrast[0] = -(mid[0] - rgbValues[k]);
				}
				else if (rgbValues[k] > mid[0] && beta < 0) {
					tempRGB[0] = rgbValues[k];
					contrast[0] = rgbValues[k] - mid[0];
				}
				if (rgbValues[k+1] < mid[1] && beta > 0) {
					tempRGB[1] = 255 - rgbValues[k+1];
					contrast[1] = -(rgbValues[k+1] - min[1]);
				}
				else if (rgbValues[k+1] > mid[1] && beta > 0) {
					tempRGB[1] = rgbValues[k+1];
					contrast[1] = max[1] - rgbValues[k+1];
				}
				else if (rgbValues[k+1] < mid[1] && beta < 0) {
					tempRGB[1] = 255 - rgbValues[k+1];
					contrast[1] = -(mid[1] - rgbValues[k+1]);
				}
				else if (rgbValues[k+1] > mid[1] && beta < 0) {
					tempRGB[1] = rgbValues[k+1];
					contrast[1] = rgbValues[k+1] - mid[1];
				}
				if (rgbValues[k+2] < mid[2] && beta > 0) {
					tempRGB[2] = 255 - rgbValues[k+2];
					contrast[2] = -(rgbValues[k+2] - min[2]);
				}
				else if (rgbValues[k+2] > mid[2] && beta > 0) {
					tempRGB[2] = rgbValues[k+2];
					contrast[2] = max[2] - rgbValues[k+2];
				}
				else if (rgbValues[k+2] < mid[2] && beta < 0) {
					tempRGB[2] = 255 - rgbValues[k+2];
					contrast[2] = -(mid[2] - rgbValues[k+2]);
				}
				else if (rgbValues[k+2] > mid[2] && beta < 0) {
					tempRGB[2] = rgbValues[k+2];
					contrast[2] = rgbValues[k+2] - mid[2];
				}
				if (rgbValues[k+3] < mid[3] && beta > 0) {
					tempRGB[3] = 255 - rgbValues[k+3];
					contrast[3] = -(rgbValues[k+3] - min[3]);
				}
				else if (rgbValues[k + 3] > mid[3] && beta > 0) {
					tempRGB[3] = rgbValues[k + 3];
					contrast[3] = max[3] - rgbValues[k + 3];
				}
				else if (rgbValues[k + 3] < mid[3] && beta < 0) {
					tempRGB[3] = 255 - rgbValues[k + 3];
					contrast[3] = -(mid[3] - rgbValues[k + 3]);
				}
				else if (rgbValues[k + 3] > mid[3] && beta < 0) {
					tempRGB[3] = rgbValues[k + 3];
					contrast[3] = rgbValues[k + 3] - mid[3];
				}



				blue = rgbValues[k] + tempRGB[0] * brightnessLevel + (contrast[0] / bt) * beta;

				//green = ((((rgbValues[k + 1] / 255.0) - 0.5) *
					//brightnessLevel) + 0.5) * 255.0;
				green = rgbValues[k + 1] + tempRGB[1] * brightnessLevel + (contrast[1] / bt) * beta;

			    //red = ((((rgbValues[k + 2] / 255.0) - 0.5) *
					//brightnessLevel) + 0.5) * 255.0;
				red = rgbValues[k + 2] + tempRGB[3] * brightnessLevel + (contrast[2] / bt) * beta;

				//alpha = ((((rgbValues[k + 3] / 255.0) - 0.5) *
				//brightnessLevel) + 0.5) * 255.0;
				alpha = rgbValues[k + 3] + tempRGB[3] * brightnessLevel + (contrast[3] / bt) * beta;


				if (blue > 255)
				{
					blue = 255;
				}
				else if (blue < 0)
				{
					blue = 0;
				}


				if (green > 255)
				{
					green = 255;
				}
				else if (green < 0)
				{
					green = 0;
				}


				if (red > 255)
				{
					red = 255;
				}
				else if (red < 0)
				{
					red = 0;
				}

				// puts the final rgb values into the byte array
				rgbValues[k] = System::Convert::ToByte(blue);
				rgbValues[k + 1] = System::Convert::ToByte(green);
				rgbValues[k + 2] = System::Convert::ToByte(red);
			}


			Bitmap^ resultBitmap = gcnew Bitmap(sourceBitmap->Width, sourceBitmap->Height);

			Rectangle rect2 = Rectangle(0, 0, resultBitmap->Width, resultBitmap->Height);
			System::Drawing::Imaging::BitmapData^ resultData = resultBitmap->LockBits(rect2,System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb);


			System::Runtime::InteropServices::Marshal::Copy(rgbValues, 0, ptr, bytes);
			resultBitmap->UnlockBits(resultData);


			return sourceBitmap;
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (pictureBox1->Image != nullptr)
		{
			//pictureBox1->Image->Dispose();  
			//pictureBox1->Image = nullptr;
		}
		
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "jpg files (*.jpg)|*.jpg|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		this->trackBar1->Value = (this->trackBar1->Maximum - this->trackBar1->Minimum) / 2;
		this->trackBar2->Value = (this->trackBar2->Maximum - this->trackBar2->Minimum) / 2;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				// You should choose your own image for processing 
				pictureBox1->Image = Image::FromFile(openFileDialog1->FileName);
				pictureBox2->Image = Image::FromFile(openFileDialog1->FileName);
				myStream->Close();
			}
		}
	
	}

    private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {

		bmp = gcnew Bitmap(pictureBox1->Image);
		int z=1;
		double maxalpha = trackBar1->Maximum;
		double minalpha = trackBar1->Minimum;
		this->maxalpha = trackBar1->Maximum;
		this->minalpha = trackBar1->Minimum;
		double valuealpha = trackBar1->Value;
		double maxbeta = trackBar2->Maximum;
		double minbeta = trackBar2->Minimum;
		this->maxbeta = trackBar2->Maximum;
		this->minbeta = trackBar2->Minimum;
		double valuebeta = trackBar2->Value;
		double y = (maxalpha - minalpha) / 2;
		double middlebeta = (maxbeta - minbeta) / 2;
		if (valuealpha - y < 0)
			z = -z;
		
		this->brightnessLevel =z*( Math::Abs(valuealpha - y) / (maxalpha / 2));
	
		std::cout << "alpha  is ";
		std::cout << this->brightnessLevel ;
		std::cout << "  ,  ";
		std::cout << "beta  is ";
		std::cout << valuebeta - middlebeta << std::endl;
		/// Do the operation new_image(i,j) = alpha*image(i,j) + beta
		/*for (int y = 0; y < bmp->Width; y++)
		{
			for (int x = 0; x < bmp->Height; x++)
			{
				for (int c = 0; c < 3; c++)
				{
					
					//bmp->SetPixel(x,y, alpha*bmp->GetPixel(x,y)->toArgb()+beta);
					//pictureBox1->Image.at<Vec3b>(y, x)[c] =
						//saturate_cast<uchar>(alpha*(image.at<Vec3b>(y, x)[c]) + beta);
				}
			}
		}*/
		//boost::thread workerThread(MyForm->ContrastBrightness);
		//Image is the one to be displayed
		this->pictureBox2->Image = ContrastBrightness(bmp,this->brightnessLevel,valuebeta - middlebeta);
    }

    private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {

		bmp = gcnew Bitmap(pictureBox1->Image);
		int z = 1;
		double maxalpha = trackBar1->Maximum;
		double minalpha = trackBar1->Minimum;
		this->maxalpha = trackBar1->Maximum;
		this->minalpha = trackBar1->Minimum;
		double valuealpha = trackBar1->Value;
		double maxbeta = trackBar2->Maximum;
		double minbeta = trackBar2->Minimum;
		this->maxbeta = trackBar2->Maximum;
		this->minbeta = trackBar2->Minimum;
		double valuebeta = trackBar2->Value;
		double y = (maxalpha - minalpha) / 2;
		double middlebeta = (maxbeta - minbeta) / 2;
		if (valuealpha - y < 0)
			z = -z;

		this->brightnessLevel = z*(Math::Abs(valuealpha - y) / (maxalpha / 2));

		std::cout << "alpha  is ";
		std::cout << this->brightnessLevel;
		std::cout << "  ,  ";
		std::cout << "beta  is ";
		std::cout << valuebeta - middlebeta << std::endl;
		
		/// Do the operation new_image(i,j) = alpha*image(i,j) + beta
		/*for (int y = 0; y < bmp->Width; y++)
		{
		for (int x = 0; x < bmp->Height; x++)
		{
		for (int c = 0; c < 3; c++)
		{

		//bmp->SetPixel(x,y, alpha*bmp->GetPixel(x,y)->toArgb()+beta);
		//pictureBox1->Image.at<Vec3b>(y, x)[c] =
		//saturate_cast<uchar>(alpha*(image.at<Vec3b>(y, x)[c]) + beta);
		}
		}
		}*/
		this->pictureBox2->Image = ContrastBrightness(bmp, this->brightnessLevel, valuebeta -middlebeta);

    } 
    private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		// Displays a SaveFileDialog so the user can save the Image
		// assigned to Button2.
		SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter =
			"JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
		saveFileDialog1->Title = "Save an Image File";
		saveFileDialog1->ShowDialog();
		// If the file name is not an empty string, open it for saving.
		if (saveFileDialog1->FileName != "")
		{
			// Saves the Image through a FileStream created by
			// the OpenFile method.
			System::IO::FileStream ^ fs =
				safe_cast<System::IO::FileStream^>(
					saveFileDialog1->OpenFile());
			// Saves the Image in the appropriate ImageFormat based on
			// the file type selected in the dialog box.
			// Note that the FilterIndex property is one based.
			switch (saveFileDialog1->FilterIndex)
			{
			case 1:
				this->pictureBox2->Image->Save(fs,
					System::Drawing::Imaging::ImageFormat::Jpeg);
				break;
			case 2:
				this->pictureBox2->Image->Save(fs,
					System::Drawing::Imaging::ImageFormat::Bmp);
				break;
			case 3:
				this->pictureBox2->Image->Save(fs,
					System::Drawing::Imaging::ImageFormat::Gif);
				break;
			}
			fs->Close();
		}
		this->trackBar1->Value = (this->trackBar1->Maximum - this->trackBar1->Minimum) / 2;
		this->trackBar2->Value = (this->trackBar2->Maximum - this->trackBar2->Minimum) / 2;
    }
};
}
