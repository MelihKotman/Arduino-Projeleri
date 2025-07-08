<h1>LCD Uygulamaları</h1>
Bu uygulamada LCD(Liquid Crystal Display)'in fonksiyonları kurulumu ve ne işe yaradığı ele alınmıştır.
LCD'yi kullanırken klasik paralel 16 pinli olarak veya I2C modülü kullanarak 4 pin şekilde kullanabiliriz.
<h2>LCD Pin Bağlantıları (Paralel ve I2C)</h2>

<table border="1" cellpadding="6" cellspacing="0" style="border-collapse: collapse; width: 100%; max-width: 700px; font-family: monospace;">
  <thead>
    <tr>
      <th>LCD Pin</th>
      <th>→ Arduino Pin</th>
      <th>Açıklama</th>
      <th style="width: 40px;"></th> <!-- boşluk için -->
      <th>I2C Pin</th>
      <th>→ Arduino UNO Pin</th>
      <th>Açıklama</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>VSS</td>
      <td>→ GND</td>
      <td>Toprak bağlantısı</td>
      <td></td>
      <td>GND</td>
      <td>→ GND</td>
      <td>Toprak bağlantısı</td>
    </tr>
    <tr>
      <td>VDD</td>
      <td>→ 5V</td>
      <td>Güç (besleme) bağlantısı</td>
      <td></td>
      <td>VCC</td>
      <td>→ 5V</td>
      <td>Güç (besleme) bağlantısı</td>
    </tr>
    <tr>
      <td>VO</td>
      <td>→ Potansiyometre</td>
      <td>Kontrast ayarı için orta bacak</td>
      <td></td>
      <td>SDA</td>
      <td>→ A4</td>
      <td>Veri hattı (Serial Data)</td>
    </tr>
    <tr>
      <td>RS</td>
      <td>→ 12</td>
      <td>Register Select (komut/veri seçimi)</td>
      <td></td>
      <td>SCL</td>
      <td>→ A5</td>
      <td>Saat hattı (Serial Clock)</td>
    </tr>
    <tr>
      <td>RW</td>
      <td>→ GND</td>
      <td>Sabit GND’ye bağlanır (yazma modu)</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>E</td>
      <td>→ 11</td>
      <td>Enable (veri gönderme tetiklemesi)</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>D4</td>
      <td>→ 5</td>
      <td>Veri hattı 4</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>D5</td>
      <td>→ 4</td>
      <td>Veri hattı 5</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>D6</td>
      <td>→ 3</td>
      <td>Veri hattı 6</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>D7</td>
      <td>→ 2</td>
      <td>Veri hattı 7</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>A (LED+)</td>
      <td>→ 5V</td>
      <td>Arka ışık pozitif terminal</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>K (LED−)</td>
      <td>→ GND</td>
      <td>Arka ışık toprak terminali</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
  </tbody>
</table>
<p><strong>9 tane uygulamalar vardır ve bu uygulamalar şu şekildedir:</strong></p>
<ul>
  <li><strong>01_print_and_cursor.ino</strong><br>
    Fonksiyonlar: <code>print()</code>, <code>setCursor()</code>, <code>cursor()</code><br>
    Yazı yazma ve imleç kontrolü.
  </li>
  <li><strong>02_clear_home.ino</strong><br>
    Fonksiyonlar: <code>clear()</code>, <code>home()</code><br>
    Ekranı temizleme ve imleci başlangıca alma.
  </li>
  <li><strong>03_print_number_formats.ino</strong><br>
    Fonksiyonlar: <code>print(value, DEC/HEX/BIN/OCT)</code><br>
    Sayıları farklı formatlarda yazdırma.
  </li>
  <li><strong>04_blink_display.ino</strong><br>
    Fonksiyonlar: <code>blink()</code>, <code>noBlink()</code><br>
    İmleci yanıp söner hale getirme.
  </li>
  <li><strong>05_scroll_display.ino</strong><br>
    Fonksiyonlar: <code>scrollDisplayLeft()</code>, <code>scrollDisplayRight()</code><br>
    Yazıyı kaydırma.
  </li>
  <li><strong>06_text_direction.ino</strong><br>
    Fonksiyonlar: <code>rightToLeft()</code>, <code>leftToRight()</code><br>
    Yazı yönünü değiştirme.
  </li>
  <li><strong>07_create_char.ino</strong><br>
    Fonksiyonlar: <code>createChar()</code>, <code>write()</code><br>
    Özel karakter oluşturma ve yazma.
  </li>
  <li><strong>08_autoscroll.ino</strong><br>
    Fonksiyonlar: <code>autoscroll()</code>, <code>noAutoscroll()</code><br>
    Otomatik kaydırmayı açıp kapama.
  </li>
  <li><strong>09_display_toggle.ino</strong><br>
    Fonksiyonlar: <code>display()</code>, <code>noDisplay()</code><br>
    Ekranı gösterme/gizleme.
  </li>
</ul>


<h2>Donanım Bileşenleri</h2>
<li>1 x Arduino UNO</li>
<li>1 x 10kΩ potansiyometre</li>
<li>1 x 220Ω direnç</li>
<li>Jumper Kablo</li>
<li>1 x LCD(Paralel veya I2C Modüllü)</li>
<li>Breadboard</li>

<h3>Devre Fotoğrafı</h3>
<img src="resim_dosyasi.jpg" alt="Alternatif metin" />
