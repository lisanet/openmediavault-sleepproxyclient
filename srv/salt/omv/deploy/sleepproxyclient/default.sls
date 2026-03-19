{% set config = salt['omv_conf.get']('conf.system.sleepproxyclient') %}

configure_sleepproxyclient:
  file.managed:
    - name: /etc/default/sleepproxyclient-omv.conf
    - source:
      - salt://{{ tpldir }}/files/etc-default-sleepproxyclient.j2
    - template: jinja
    - context:
        config: {{ config | json }}
    - user: root
    - group: root
    - mode: 644
