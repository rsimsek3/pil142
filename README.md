# bil142
bil142 gemi oyunu
ömer yarın yavaş yavaş koyalım şimdilik kendi bilgisayarımda yazıyorum o yüzden anlaşılır değil yarın ilk kısmı koyalım 
tarih 13.03.2024
kardeşimin bilgisayarına geçtim.Classları yüklüyorum.-Rasih Görkem Şimşek
14.03.2024

Adlandırmayı değiştirelim ingilizce karakterlere uygun olsun. ı ve ü olmasın. Değişken adlandırmasında büyük harf kuralına dikkat ederek yapalım. Yazdığın gemi classlarını interface gemi sınıfından kalıtım alarak gerçekleştirelim. Pure virtual fonksiyon kullanarak interface base class oluşturalım. 
İnterface base classı pure virtual fonksiyonlarla oluşturdum kullanacağımız 3 gemi sınıfına interface üzerinden türettim. 3 Farklı gemi özelliğine göre sınıf fonksiyonlarını yazdım bu şekilde gemilerin alınan hasarları ve kaçma olasılıkları türlerine göre farklı olacak. 
~Ömer Faruk İnciler 15.03.2024
Dün eklemeyi unuttum.Uzay korsanları fonksiyonunu ekledim bugün. Tekrar göz gezdirdim yazdığımız kodlara oyunu classların içinde olmayan 3 fonksiyon ile oynamamız güzel olmuş.Interface ve sublarda olan overrided fonksiyonlar şeklinde olsaydı boşa kopyalamalar yapılmış olurdu,daha yavaş çalışırdı,boyut büyürdü ve Solid principles'ın Single responsibility ilkesine aykırı olurdu.Belki rand yerine başka alternatif eklenebilir. Yarın smart pointerlı ve endl'lerin \n'lerle değiştirilmiş halini yükleyecez.Uml diagramını da githuba yükleyecez. -Rasih Görkem Şimşek 17.03.2024
Yarın magic numberları da kaldıracaz ve headerlara ve diğer cpp lere ayıracaz kodu.-Rasih Görkem Şimşek 17.03.2024
Header ve cpp'lere ayrıldıktan sonra ayrı ayrı yükleyecez -Rasih Görkem Şimşek -18.03.2024
Şimdilik ayırmayı başaramazsak diye çalışan son smart pointerlı ve const correctnesslı kodu main.cpp'ye yükledim -Rasih Görkem Şimşek

Shared pointer kullandığımız için header ve cpp dosyalarına ayrıştıramamışız. Diğer yapanlar unique pointer kullanarak sorunu çözeceğimizi söyledirler. Bunun için kodu uniqe pointer kullanarak header ve cpp dosyalarına ayrıştırdım. - Ömer Faruk İnciler
