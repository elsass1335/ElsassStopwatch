# include <Siv3D.hpp> // Siv3D v0.6.12

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	Stopwatch stopwatch{ StartImmediately::No };

	while (System::Update())
	{
		double t = stopwatch.sF();
		font(U"{:.2f}"_fmt(t)).draw(196, Vec2{100, 100}, Palette::Black);

		// ボタン | Button
		if (SimpleGUI::Button(U"pause", Vec2{ 480, 480 }))
		{
			if (stopwatch.isRunning())
			{
				stopwatch.pause();
			}
			else
			{
				continue;
			}
		}

		if (SimpleGUI::Button(U"resume", Vec2{ 640, 480 }))
		{
			if (stopwatch.isPaused())
			{
				stopwatch.resume();
			}
			else
			{
				continue;
			}
		}

		if (SimpleGUI::Button(U"start", Vec2{ 320, 480 }))
		{
			if (stopwatch.isStarted())
			{
				continue;
			}
			else
			{
				stopwatch.start();
			}
		}

		if (SimpleGUI::Button(U"reset", Vec2{ 160, 480 }))
		{
			if (stopwatch.isStarted())
			{
				stopwatch.reset();
			}
			else
			{
				continue;
			}
		}
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
