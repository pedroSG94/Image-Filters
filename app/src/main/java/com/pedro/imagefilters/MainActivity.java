package com.pedro.imagefilters;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import com.pedro.imagefilter.AndroidImageFilter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStream;

public class MainActivity extends AppCompatActivity {

  private Bitmap bOrigin;
  private Bitmap bResult;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    BitmapFactory.Options options = new BitmapFactory.Options();
    options.inPreferredConfig = Bitmap.Config.ARGB_8888;


    bOrigin = BitmapFactory.decodeResource(getResources(), R.drawable.trump, options);
    final ImageView imageView = (ImageView) findViewById(R.id.image);
    Button button = (Button) findViewById(R.id.button);
    button.setOnClickListener(new View.OnClickListener() {
      @Override
      public void onClick(View v) {
        bResult =
            Bitmap.createBitmap(bOrigin.getWidth(), bOrigin.getHeight(), Bitmap.Config.ARGB_8888);
        AndroidImageFilter androidImageFilter = new AndroidImageFilter();
        androidImageFilter.blueScale(bOrigin, bResult);
        imageView.setImageBitmap(bResult);
        try {
          OutputStream os = new FileOutputStream(Environment.getExternalStorageDirectory() + "/foto.jpg");
          bResult.compress(Bitmap.CompressFormat.JPEG, 100, os);
        } catch (FileNotFoundException e) {
          e.printStackTrace();
        }
      }
    });
    Button button2 = (Button) findViewById(R.id.button2);
    button2.setOnClickListener(new View.OnClickListener() {
      @Override
      public void onClick(View v) {
        bResult = Bitmap.createBitmap(bOrigin.getWidth(), bOrigin.getHeight(), Bitmap.Config.ARGB_8888);
        AndroidImageFilter androidImageFilter = new AndroidImageFilter();
        androidImageFilter.whiteBalance(bOrigin, bResult);
        imageView.setImageBitmap(bResult);
        try {
          OutputStream os = new FileOutputStream(Environment.getExternalStorageDirectory() + "/foto.jpg");
          bResult.compress(Bitmap.CompressFormat.JPEG, 100, os);
        } catch (FileNotFoundException e) {
          e.printStackTrace();
        }
      }
    });
  }
}
