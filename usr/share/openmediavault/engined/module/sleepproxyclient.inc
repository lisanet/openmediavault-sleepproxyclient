<?php
/**
 * @license   MIT 
 * @author    Simone Karin Lehmann
 */


class OMVModuleSleepProxyClient extends \OMV\Engine\Module\ServiceAbstract
    implements \OMV\Engine\Notify\IListener
{
    public function getName()
    {
        return 'sleepproxyclient';
    }

    function bindListeners(\OMV\Engine\Notify\Dispatcher $dispatcher)
    {
        $dispatcher->addListener(
            OMV_NOTIFY_MODIFY,
            'org.openmediavault.conf.system.sleepproxyclient',
            [$this, 'setDirty']
        );
    }
}
