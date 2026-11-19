package tp4;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class BucketTest {

    @Test
    public void TestVide() throws Exception {
        Bucket a = new Bucket(2);
        assertEquals(2,a.vide(3));
    }

    @Test
    public void TestRemplit() throws Exception {
        Bucket a = new Bucket(0);
        a.remplit(2);
        assertEquals(2,a.vide(3));
    }

    @Test
    public void TestVide2() throws Exception {
        Bucket a = new Bucket(6);
        assertEquals(3,a.vide(3));
    }

    @Test
    public void TestRemplit2() throws Exception {
        Bucket a = new Bucket(1);
        a.remplit(2);
        assertEquals(3,a.vide(3));
    }

}
